module mod1();
    wire clk_cpu;  // for cpu components except hazard_unit (100MHz)
    wire clk_vga;  // for vga_unit (25MHz)
    wire clk_uart; // for uart_unit (10MHz)
    wire clk_tube; // for seven_seg_unit
endmodule
