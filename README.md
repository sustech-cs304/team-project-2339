# CPU Debugger

This project is an assistant software for students in CS208-Compute Organization, providing a convenience method to debug CPU written by verilog and assemble language codes needed on course.

## Usage

### Architecture

This package aims to provide a straightforward experience for students or hobbyists looking to develop and debug their Verilog MIPS CPU design. The package consists of 2 parts, a `debug_core.v` Debug Core coprocessor that is to be injected into the CPU and programmed into the FPGA, and a PC Client that interacts with the injected coprocessor. 

The typical workflow is as follows:

1. Develop CPU implementing debug required hardware interfaces.
2. Use the PC Client to generate the coprocessor.
3. Write generated bitstream to the FPGA.
4. Use the PC Client to program the ASM file into the CPU.
5. Use the PC Client to check signals in the CPU during ASM execution and control the CPU’s execution.

This package provides interfaces for the CPU to implement in order to provide probing and CPU execution control from the PC application. The PC Client and Debug Core manuals will be provided below.

### PC Client

This section introduces the operations for utilizing the CPU Debugger PC client. There’re 4 stages for the PC Client, and it’s possible to return to any previous stage.

1. ****CPU Import Stage****:
    
    ![0 import](documentations/User Manual/graphs/0%20import.png)
    
    - `1`: Select the CPU directory with the dark gray button or simply drag the directory (alternative) into the dashed box as shown in the graph.
        
        <aside>
        <img src="https://www.notion.so/icons/info-alternate_gray.svg" alt="https://www.notion.so/icons/info-alternate_gray.svg" width="40px" /> 
        
        For all the dashed indicators present in the illustrations:
        
        - those that have the same indices as other indicators are alternatives
        - others that have different indices than other indicators are optional steps
        
        Note that indices with decimals (`1.2` and `1.1`) denote that no order is enforced (`1.1` can be after `1.2`).
        
        </aside>
        
        The CPU directory is the highest-level directory that should include all the `.v` Verilog files that define the CPU. 
        
        <aside>
        <img src="https://www.notion.so/icons/warning_red.svg" alt="https://www.notion.so/icons/warning_red.svg" width="40px" />
        
        The `top.v` file (with this exact name) **must be available** and **must be used to interconnect all the modules** in the CPU.
        
        </aside>
        
    - `2.1`: Start the process of syntax analysis of all Verilog files present in the directory.
    - `2.2`: Wait for the progress bar to complete, this process will take a while if large Verilog files are present.
2. ******Signal Select Stage******:
    
    ![1 signal](graphs/1%20signal.png)
    
    - `3.1`: (Optional) Search for a specific signal wire by specifying its name or part of its name, note that searching merely reorders the list, no signals will be masked. This is useful for CPUs with many signals at the `top.v` module.
    - `3.2`: Select signals to probe. Selected signals’ values will be available during ASM execution.
    - `3.3`: (Optional) Hide the signal select list, note that this does not hide the “Signals Selected” list that is at the leftmost of the window. Pressing the button again will reveille the signal select list again. This is helpful when using graph visualization to inspect the structure of the `top.v` module.
    - `3.4`: (Optional) Remove a signal that has been selected.
    - `3.5`: (Optional) Return to the previous stage if something from the previous page must be remedied. Any stage prior to the current stage will be available for rollback, any stage after the current stage will not be selectable.
    - `4`: (Optional) Get a brief explanation of the selected signals.
        
        <aside>
        <img src="https://www.notion.so/icons/info-alternate_gray.svg" alt="https://www.notion.so/icons/info-alternate_gray.svg" width="40px" /> 
        
        The signals selected will be probed and have their values monitored in real-time during the debug stage.
        
        </aside>
        
    - `5`: Confirm the signal selection and proceed to the next stage.
3. ****************Export Stage****************:
    
    ![2 export](graphs/2%20export.png)
    
    - `6`: Select a directory to export the `debug_core.v` Debug Core coprocessor, this directory will default to the directory previously specified for the entire CPU.
    - `7`: This button will become active after the bitstream has been flashed into the FPGA, press it to complete the export stage.
4. **********************Debug Stage**********************:
    
    ![3 debug](graphs/3%20debug.png)
    
    - `8`: Select an ASM file to be imported to the CPU Debugger.
    - `9`: Send the assembled ASM file in binary format to the CPU, the CPU must have RAM and ROM sizes of 64K (details will be provided below).
    - `10.1`: Select a breakpoint where the CPU will pause upon finishing executing that instruction.
    - `10.2`: Resume CPU execution until the next breakpoint, note that this only respects each line in the ASM file, for a pseudo instruction that has been expanded into multiple different instructions, the CPU Debugger will only register the last instruction as the breakpoint.
    - `10.3`: Execute the next ASM instruction, this will ensure that only a single instruction is executed, that is, the pause is lifted for a single cycle, it will be possible that the ASM line highlight does not move after pressing this button as pseudo instructions will be executed instruction by instruction.
    - `10.4`: Pause the CPU under whatever circumstances, this is designed to pause the CPU in an endless loop.

### CPU

This section provides details on what hardware interfaces must be implemented in order to enable the Debug Core coprocessor. There’s a complete implementation of a pipelined CPU design described [here](https://www.notion.so/CS202-Computer-Organization-Final-Project-Pipelined-CPU-with-IO-8be3216a2b4d4669976a58cf52900514) which can be found in the repo’s `example/module_files` directory.

Only the signals that Debug Core takes in or outputs as shown below are necessary to be implemented.

```verilog
input clk, rst_n,

input      uart_rx,
output reg uart_tx,

input      [`ISA_WIDTH - 1:0] pc,
input      [`ISA_WIDTH - 1:0] pc_next,

output reg [`RAM_DEPTH:0] uart_addr,
output reg [`ISA_WIDTH - 1:0] uart_data,
output reg uart_write_enable,

output reg debug_pause,
output reg uart_complete
```

- `clk` and `rst_n` signals must be identical to which the CPU uses, that is, the Debug Core operates at the same frequency as the CPU. Currently the Debug Core must operate at the frequency of **100MHz**, if this frequency is to be changed, be sure to update the parameters `PERIOD_WIDTH`, `FULL_PERIOD`, and `HALF_PERIOD` which are used to convert the CPU’s frequency to UART’s frequency.
- `uart_rx` and `uart_tx` signals are for UART reception and transmission, respectively. Note that no other modules should be using UART except the Debug Core.
- `pc` is the value of the program counter of the current cycle.
- `pc_next` is the value of the program counter of the next cycle, this must be able to reflect any changes (reset to 0, jump, or offset) right after they happen.
- `uart_addr` is the address for writing the received ASM binary into RAM and ROM. As shown in the graph below, the data memory and instruction memory will be sent at a single package with different addresses, be sure that the RAM and ROM are both of 64K and provide a logic that saves the upper 64K into RAM (for data) and lower 64K into ROM (for instruction).

![UART_Address.png](graphs/UART_Address.png)

- `uart_data` is the specific value of a word in the memory corresponding to its address, here the RAM and ROM must be word-aligned.
- `uart_write_enable` is the enable signal that denotes the competition of receiving a word from UART. This goes high for a single cycle and should typically be connected to the `ena` port of the block RAM IP core’s module instance.
- `debug_pause` is the control signal that the coprocessor lets out, this signals the CPU that it should pause immediately and the next instruction will not be executed in the next cycle.
- `uart_complete` signals the completion of receiving all data from UART, in exact, this denotes that the entire UART transmission package has been received.

With all the above signals dealt with and utilized, the Debug Core will be able to function correctly after its automatic export by the PC Client. Note that all the above signals must be available in the `top.v` module where the Debug Core will be instantiated.
