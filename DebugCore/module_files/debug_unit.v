`timescale 1ns / 1ps
`include "./definitions.v"

module debug_unit (
    input clk, rst_n,

    input      uart_rx,                         // 
    output reg uart_tx,                         // 

    input      [`ISA_WIDTH - 1:0] pc,           //

    //// [TODO] demo only !!! ////
    input      [`ISA_WIDTH - 1:0] instruction,  // from instruction_mem

    output reg [`RAM_DEPTH:0] uart_addr,        // 
    output reg [`ISA_WIDTH - 1:0] uart_data,    // 
    output     uart_write_enable,               // for (1) hazard_unit
                                                //     (2) instruction_mem
                                                //     (3) data_mem

    output reg debug_pause,                     // for hazard_unit (to pause the CPU)
    output reg uart_complete                    // for hazard_unit (programming completed)
    );

    localparam  ISA_BYTE_CNT       = `ISA_WIDTH / 8 - 1,    // number of bytes in an instruction - 1
                ISA_BYTE_IDX_WIDTH = 2;                     // ceil(sqrt(`ISA_WIDTH / 8)): has to be calculated [TODO]
    reg [ISA_BYTE_IDX_WIDTH - 1:0] uart_byte_idx;

    localparam  PERIOD_WIDTH = 10,
                FULL_PERIOD  = 10'd867,             // CPU clock to UART clock (100MHz -> 115200Hz) - last cycle
                HALF_PERIOD  = 10'd432;             // 868 / 2 - 2: half of delay (to capture the center of a bit) - discover cycle - last cycle
    // localparam  PERIOD_WIDTH = 10,
    //             FULL_PERIOD  = 7,
    //             HALF_PERIOD  = 2;
    reg [PERIOD_WIDTH - 1:0] rx_delay, tx_delay;

    localparam  // to client
                OP_SIGNAL  = 8'h01, // send pc and all signals
                OP_OK      = 8'h02, // received ping
                // from client
                OP_PING    = 8'h03, // ping the debug unit
                OP_PAUSE   = 8'h04, // pause the CPU
                OP_RESUME  = 8'h05, // resume the CPU
                OP_NEXT    = 8'h06, // execute the next instruction
                OP_PROGRAM = 8'h07; // reprogram the CPU

    localparam  RX_STATE_WIDTH = 3,
                RX_IDLE        = 3'b000,    // uart waiting for input
                RX_START       = 3'b001,    // start bit detected
                RX_DATA        = 3'b010,    // collecting data bits
                RX_STOP        = 3'b011,    // stop bit detected
                RX_WAIT        = 3'b100;    // wait for the next byte to carry on
    reg [RX_STATE_WIDTH - 1:0] rx_state;

    localparam  TX_STATE_WIDTH = 1,
                TX_IDLE        = 1'b0,  // uart waiting for output
                TX_SEND        = 1'b1;  // sending the data (with start and stop bits)
    reg tx_state;

    localparam  CORE_RX_STATE_WIDTH = 2,
                CORE_RX_OPCODE      = 2'b00,    // analyze opcode
                CORE_RX_PROGRAM     = 2'b01,    // receive program
                CORE_RX_PC          = 2'b10;    // receive breakpoint pc
    reg [CORE_RX_STATE_WIDTH - 1:0] core_rx_state;

    localparam  CORE_TX_STATE_WIDTH = 2,
                CORE_TX_IDLE        = 2'b00,
                CORE_TX_SIGNAL      = 2'b01,    // send signals
                CORE_TX_PING        = 2'b10;    // respond ok to ping
    reg [CORE_TX_STATE_WIDTH - 1:0] core_tx_state;
    reg                             core_tx_up;
    
    localparam  SIGNALS_WIDTH          = `ISA_WIDTH * 2,            //// [TODO] demo only !!! ////
                SIGNALS_BYTE_CNT       = SIGNALS_WIDTH / 8 - 1,
                SIGNALS_BYTE_CNT_WIDTH = 3;                         // ceil(sqrt(SIGNALS_WIDTH / 8)): has to be calculated [TODO]
    reg  [SIGNALS_BYTE_CNT_WIDTH - 1:0] signals_byte_idx;
    wire [SIGNALS_WIDTH - 1:0]          signals = {
                                                      instruction,
                                                      pc
                                                  };                //// [TODO] demo only !!! ////
    
    reg       rx_bit_buffer, rx_bit;
    reg [2:0] rx_bit_idx; 
    reg [7:0] rx_byte;
    reg       rx_complete;

    reg [3:0] tx_bit_idx;   // accomodates total of 10 bits
    reg [9:0] tx_byte;
    reg       tx_start, tx_complete;

    reg [`ISA_WIDTH - 1:0] breakpoint;
    wire                   breakpoint_reached = (breakpoint == pc);

    reg    debug_write_enable;
    assign uart_write_enable = debug_write_enable & rx_complete;

    always @(posedge clk, negedge rst_n) begin
        if (~rst_n) begin
            rx_bit_buffer <= 1'b1;
            rx_bit        <= 1'b1;
        end else begin
            /*
                double-register barrier for incoming UART signal to remove instabilities
             */
            rx_bit_buffer <= uart_rx;
            rx_bit        <= rx_bit_buffer;
        end
    end

    // RX
    always @(posedge clk, negedge rst_n) begin
        if (~rst_n) begin
            rx_bit_idx    <= 0;
            rx_byte       <= 0;
            rx_complete   <= 1'b0;
            rx_state      <= RX_IDLE;
            rx_delay      <= 0;

            uart_complete <= 1'b0;
        end else begin
            case (rx_state)
                RX_IDLE  : begin
                    uart_complete <= 1'b0;

                    if (~rx_bit) rx_state <= RX_START;
                    else         rx_state <= rx_state; // prevent auto latches
                end
                RX_START : begin
                    if (rx_delay == HALF_PERIOD) begin
                        rx_delay <= 0;
                        rx_state <= rx_bit ? RX_IDLE : RX_DATA; // return to IDLE if high
                    end else
                        rx_delay <= rx_delay + 1;
                end
                RX_DATA  : begin
                    if (rx_delay == FULL_PERIOD) begin
                        rx_delay            <= 0;
                        rx_byte[rx_bit_idx] <= rx_bit;

                        if (rx_bit_idx == 3'd7) begin
                            rx_bit_idx      <= 0;
                            rx_state        <= RX_STOP;
                        end else 
                            rx_bit_idx      <= rx_bit_idx + 1;
                    end else
                        rx_delay            <= rx_delay + 1;
                end
                RX_STOP  : begin
                    if (rx_delay == FULL_PERIOD) begin
                        rx_delay    <= 0;
                        rx_complete <= 1'b1;
                        rx_state    <= RX_WAIT;
                    end else
                        rx_delay    <= rx_delay + 1;
                end
                RX_WAIT  : begin
                    rx_complete = 1'b0;

                    casex ({~rx_bit, rx_delay == FULL_PERIOD})
                        // next start bit begins
                        2'b1x  : begin
                            rx_delay      <= 0;
                            rx_state      <= RX_START;
                        end
                        // waited for a full cycle (bit after stop is not start bit)
                        2'b01  : begin
                            rx_delay      <= 0;
                            rx_state      <= RX_IDLE;

                            uart_complete <= (core_rx_state == CORE_RX_PROGRAM);    // (1) notify hazard unit that the transfer is completed
                                                                                    // (2) turn off debug_write_enable
                        end
                        default:
                            rx_delay      <= rx_delay + 1; 
                    endcase
                end
                default  :
                    rx_state <= rx_state;
            endcase
        end
    end
    
    // TX
    always @(posedge clk, negedge rst_n) begin
        if (~rst_n) begin
            tx_bit_idx  <= 0;
            tx_state    <= TX_IDLE;
            tx_delay    <= 0;
            tx_complete <= 1'b0;

            uart_tx     <= 1'b1;
        end else if (tx_state == TX_IDLE) begin
            uart_tx     <= 1'b1;
            tx_complete <= 1'b0;

            if (tx_start) tx_state <= TX_SEND;
            else          tx_state <= tx_state;
        end else begin
            uart_tx <= tx_byte[tx_bit_idx];

            if (tx_delay == FULL_PERIOD) begin
                tx_delay        <= 0;
                
                if (tx_bit_idx == 4'd9) begin
                    tx_bit_idx  <= 0;
                    tx_complete <= 1'b1;
                    tx_state    <= TX_IDLE;
                end else
                    tx_bit_idx  <= tx_bit_idx + 1;
            end else
                tx_delay        <= tx_delay + 1;
        end
    end

    always @(posedge tx_complete, posedge core_tx_up, negedge rst_n) begin
        case (core_tx_state)
            CORE_TX_SIGNAL : begin
                tx_byte[1+:8] <= signals[(signals_byte_idx * 8)+:8];

                if (signals_byte_idx == SIGNALS_BYTE_CNT) begin
                    tx_start         <= 1'b0;
                    signals_byte_idx <= 0;
                end else begin
                    tx_start         <= 1'b1;
                    signals_byte_idx <= signals_byte_idx + 1;
                end
            end
            CORE_TX_PING   : begin
                if (~tx_complete) begin
                    tx_start      <= 1'b1;
                    tx_byte[1+:8] <= OP_OK;
                end else 
                    tx_start      <= 1'b0;
            end
            /* CORE_TX_IDLE */
            default        : begin
                tx_start         <= 1'b0;
                signals_byte_idx <= 0;
                tx_byte          <= {1'b1, {8{1'b0}}, 1'b0};
            end
        endcase
    end

    always @(posedge rx_complete,        posedge uart_complete, 
             posedge breakpoint_reached, negedge rst_n        ) begin
        if (~rst_n) begin
            {
                uart_addr,
                uart_data,
                uart_byte_idx
            }                  = 0;

            debug_write_enable = 1'b0;
            breakpoint         = 0;
            debug_pause        = 1'b1;

            core_rx_state      = CORE_RX_OPCODE;
            core_tx_state      = CORE_TX_IDLE;
            core_tx_up         = 1'b0;
        end else begin
            case (core_rx_state)
                CORE_RX_OPCODE  : begin
                    /* 
                        (1) positive-edge of the rx_complete signal for opcode
                     */
                    core_tx_up = 1'b0;

                    case (rx_byte)
                        // receive additional data
                        OP_RESUME  : begin
                            core_rx_state = CORE_RX_PC;
                        end
                        OP_PROGRAM : begin
                            debug_pause   = 1'b1;
                            core_rx_state = CORE_RX_PROGRAM;
                        end
                        // send data back to PC
                        OP_PING    : begin
                            core_tx_state = CORE_TX_PING;
                            core_tx_up    = 1'b1;
                        end
                        OP_PAUSE   : begin
                            debug_pause   = 1'b1;
                            core_tx_state = CORE_TX_SIGNAL;
                            core_tx_up    = 1'b1;
                        end
                        // trigger breakpoint_reached in next cycle
                        OP_NEXT    : begin
                            breakpoint    = breakpoint + 4;
                        end
                        default    :
                            if (breakpoint_reached) begin
                                debug_pause   = 1'b1;
                                core_tx_state = CORE_TX_SIGNAL;
                                core_tx_up    = 1'b1;
                            end else
                                core_rx_state = core_rx_state; // prevent auto latches
                    endcase
                end
                CORE_RX_PROGRAM : begin
                    /* 
                        (2) positive-edge of the rx_complete signal for program
                     */
                    if (uart_complete) begin
                        core_rx_state      = CORE_RX_OPCODE;

                        uart_data          = 0;
                        uart_addr          = 0;
                        uart_byte_idx      = 0;

                        debug_write_enable = 1'b0;
                    end else if (uart_byte_idx == ISA_BYTE_CNT) begin
                        uart_data[(uart_byte_idx * 8)+:8] = rx_byte;

                        uart_addr          = uart_addr + 1;
                        uart_byte_idx      = 0;

                        debug_write_enable = 1'b1;
                    end else begin
                        uart_data[(uart_byte_idx * 8)+:8] = rx_byte;

                        uart_byte_idx      = uart_byte_idx + 1;
                    end
                end
                CORE_RX_PC      : begin
                    if (uart_byte_idx == ISA_BYTE_CNT) begin
                        core_rx_state = CORE_RX_OPCODE;

                        breakpoint    = {rx_byte, uart_data[`ISA_WIDTH - 8:0]};

                        uart_data     = 0;
                        uart_byte_idx = 0;

                        debug_pause   = 1'b0;
                    end else begin
                        uart_data[(uart_byte_idx * 8)+:8] = rx_byte;

                        uart_byte_idx = uart_byte_idx + 1;
                    end
                end
                default       : 
                    core_rx_state = core_rx_state; // prevent auto latches
            endcase
        end
    end

endmodule