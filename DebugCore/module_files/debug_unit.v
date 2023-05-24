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
    output reg uart_write_enable,               // for (1) hazard_unit
                                                //     (2) instruction_mem
                                                //     (3) data_mem

    output [7:0] rx_light,

    output reg debug_pause,                     // for hazard_unit (to pause the CPU)
    output reg uart_complete                    // for hazard_unit (programming completed)
    );

    localparam  ISA_BYTE_CNT       = `ISA_WIDTH / 8 - 1,    // number of bytes in an instruction - 1
                ISA_BYTE_IDX_WIDTH = 2;                     // ceil(sqrt(`ISA_WIDTH / 8)): has to be calculated [TODO]
    reg [ISA_BYTE_IDX_WIDTH - 1:0] uart_byte_idx;

    localparam  PERIOD_WIDTH = 10,
                FULL_PERIOD  = 10'd867,             // CPU clock to UART clock (100MHz -> 115200Hz) - last cycle
                HALF_PERIOD  = 10'd432;             // 868 / 2 - 2: half of delay (to capture the center of a bit) - discover cycle - last cycle
    reg [PERIOD_WIDTH - 1:0] rx_delay, tx_delay;

    localparam  UART_LEN       = 8,             // number of bits in a uart packet
                UART_LEN_WIDTH = 3,             // sqrt(UART_LEN)
                UART_RX_CNT    = UART_LEN - 1,
                UART_TX_CNT    = UART_LEN + 1;

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
                CORE_RX_PC          = 2'b10,    // receive breakpoint pc
                CORE_RX_NEXT        = 2'b11;    // execute next instruction
    reg [CORE_RX_STATE_WIDTH - 1:0] core_rx_state;

    localparam  CORE_TX_STATE_WIDTH = 2,
                CORE_TX_IDLE        = 2'b00,
                CORE_TX_SIGNAL      = 2'b01,    // send signals
                CORE_TX_PING        = 2'b10;    // respond ok to ping
    reg [CORE_TX_STATE_WIDTH - 1:0] core_tx_state;
    
    localparam  SIGNALS_WIDTH          = `ISA_WIDTH * 2 + 8,        //// [TODO] demo only !!! ////
                SIGNALS_BYTE_CNT       = SIGNALS_WIDTH / 8,
                SIGNALS_BYTE_CNT_WIDTH = 4;                         // ceil(sqrt(SIGNALS_WIDTH / 8)): has to be calculated [TODO]
    reg  [SIGNALS_BYTE_CNT_WIDTH - 1:0] signals_byte_idx;
    wire [SIGNALS_WIDTH - 1:0]          signals = {
                                                      instruction,
                                                      pc_cache,
                                                      OP_SIGNAL
                                                  };                //// [TODO] demo only !!! ////
    
    reg                        rx_bit_buffer, rx_bit;
    reg [UART_LEN_WIDTH - 1:0] rx_bit_idx; 
    reg [UART_LEN - 1:0]       rx_byte;
    reg                        rx_complete;

    reg [UART_LEN_WIDTH:0]     tx_bit_idx;   // 1 more bit to accomodate total of 10 bits
    reg [UART_LEN + 1:0]       tx_byte;
    reg                        tx_start, tx_complete;

    reg [`ISA_WIDTH - 1:0] pc_cache;
    reg [`ISA_WIDTH - 1:0] breakpoint;
    wire                   breakpoint_reached = (breakpoint == pc);

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
    always @(negedge clk, negedge rst_n) begin
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

                        if (rx_bit_idx == UART_RX_CNT) begin
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
    always @(negedge clk, negedge rst_n) begin
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
                
                if (tx_bit_idx == UART_TX_CNT) begin
                    tx_bit_idx  <= 0;
                    tx_complete <= 1'b1;
                    tx_state    <= TX_IDLE;
                end else
                    tx_bit_idx  <= tx_bit_idx + 1;
            end else
                tx_delay        <= tx_delay + 1;
        end
    end

    assign rx_light = {debug_pause, 5'b0, core_tx_state};

    always @(posedge clk, negedge rst_n) begin
        if (~rst_n) begin
            pc_cache           <= 0;

            // transmission
            tx_byte            <= {1'b1, {(UART_LEN){1'b0}}, 1'b0};
            tx_start           <= 1'b0;
            signals_byte_idx   <= 1;
            core_tx_state      <= CORE_TX_IDLE;
            
            // reception
            {
                uart_data,
                uart_byte_idx
            }                  <= 0;
            uart_addr          <= -1;
            uart_write_enable  <= 1'b0;
            breakpoint         <= 0;
            debug_pause        <= 1'b1;
            core_rx_state      <= CORE_RX_OPCODE;
        end else begin
            // transmission FSM
            case (core_tx_state)
                CORE_TX_SIGNAL :
                    case ({tx_complete, signals_byte_idx == SIGNALS_BYTE_CNT})
                        2'b11  : begin
                            core_tx_state        <= CORE_TX_IDLE;

                            tx_start             <= 1'b0;
                            signals_byte_idx     <= 1; // starts from 1 as the 0th byte will be sent when received opcode
                        end
                        2'b10  : begin
                            signals_byte_idx     <= signals_byte_idx + 1;
                            tx_byte[1+:UART_LEN] <= signals[(signals_byte_idx * UART_LEN)+:UART_LEN];
                        end
                        default:
                            core_tx_state <= core_tx_state; // prevent auto latches
                    endcase
                CORE_TX_PING   : begin
                    if (tx_complete) begin
                        core_tx_state <= CORE_TX_IDLE;

                        tx_start      <= 1'b0;
                    end else 
                        core_tx_state <= core_tx_state; // prevent auto latches
                end
                default        :
                    casex ({(breakpoint_reached | (core_rx_state == CORE_RX_NEXT)) & ~debug_pause, 
                            rx_complete         & (core_rx_state == CORE_RX_OPCODE)})
                        2'b1x  : begin // after reaching the breakpoint
                            debug_pause          <= 1'b1;
                            core_tx_state        <= CORE_TX_SIGNAL;

                            tx_start             <= 1'b1;
                            tx_byte[1+:UART_LEN] <= signals[0+:UART_LEN];
                            pc_cache             <= pc;
                        end
                        2'b01  : // after receiving the opcode
                            case (rx_byte)
                                // send data back to PC
                                OP_PING    : begin
                                    core_tx_state        <= CORE_TX_PING;
                                    
                                    tx_start             <= 1'b1;
                                    tx_byte[1+:UART_LEN] <= OP_OK;
                                end
                                OP_PAUSE   : begin
                                    debug_pause          <= 1'b1;
                                    core_tx_state        <= CORE_TX_SIGNAL;

                                    tx_start             <= 1'b1;
                                    tx_byte[1+:UART_LEN] <= signals[0+:UART_LEN];
                                end
                                default    : 
                                    core_tx_state <= CORE_TX_IDLE;
                            endcase 
                        default: 
                            core_tx_state <= core_tx_state; // prevent auto latches
                    endcase
            endcase
            // reception FSM
            if (rx_complete | uart_complete |   // after receiving a byte or no additional bytes to be received
                core_rx_state == CORE_RX_NEXT)  // takes care of the next instruction
                case (core_rx_state)                        
                    CORE_RX_PROGRAM : begin
                        if (uart_complete) begin
                            core_rx_state      <= CORE_RX_OPCODE;

                            uart_addr          <= -1;
                            uart_data          <= 0;

                            debug_pause        <= 1'b0; // enable signal sending
                            breakpoint         <= 0;
                        end else if (uart_byte_idx == ISA_BYTE_CNT) begin
                            uart_data[(uart_byte_idx * UART_LEN)+:UART_LEN] <= rx_byte;

                            uart_addr          <= uart_addr + 1;
                            uart_byte_idx      <= 0;
                            uart_write_enable  <= 1'b1; // only up for a single cycle
                        end else begin
                            uart_data[(uart_byte_idx * UART_LEN)+:UART_LEN] <= rx_byte;

                            uart_byte_idx      <= uart_byte_idx + 1;
                        end
                    end
                    CORE_RX_PC      : begin
                        if (uart_byte_idx == ISA_BYTE_CNT) begin
                            core_rx_state <= CORE_RX_OPCODE;

                            breakpoint    <= {rx_byte, uart_data[`ISA_WIDTH - UART_LEN:0]};

                            uart_data     <= 0;
                            uart_byte_idx <= 0;

                            debug_pause   <= 1'b0;
                        end else begin
                            uart_data[(uart_byte_idx * UART_LEN)+:UART_LEN] <= rx_byte;

                            uart_byte_idx <= uart_byte_idx + 1;
                        end
                    end
                    CORE_RX_NEXT    : begin
                        debug_pause   <= 1'b1;
                        core_rx_state <= CORE_RX_OPCODE;
                    end
                    /* CORE_RX_OPCODE */
                    default         :
                        case (rx_byte)
                            // receive additional data
                            OP_RESUME  : begin
                                debug_pause   <= 1'b1;
                                core_rx_state <= CORE_RX_PC;
                            end
                            OP_PROGRAM : begin
                                uart_write_enable <= 1'b1; // set the CPU to start receiving UART program
                                core_rx_state     <= CORE_RX_PROGRAM;
                            end
                            // will be back to this state after the next cycle
                            OP_NEXT    : begin
                                debug_pause   <= 1'b0;
                                core_rx_state <= CORE_RX_NEXT;
                            end
                            default    :
                                core_rx_state <= core_rx_state; // prevent auto latches
                        endcase
                endcase
            else
                uart_write_enable <= 1'b0;
        end
    end

endmodule