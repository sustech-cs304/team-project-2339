# CS304 Project Milestone 1

## Motivation

Hardware programming has few debugging tools and is mostly bundled with bulky IDEs such as VIVADO. The processes of using those debuggers are often tedious and complex, which becomes a great obstacle when students start designing their implementation of a CPU and are met with numerous bugs undetectable during hardware simulation.

CPUs are complex, and sometimes the translation from a hardware descriptive language to an FPGA programming bitstream can be inaccurate and needs that portion of code rewritten. But during normal CPU execution, there’s no way to press pause and peek into the various signals present in the CPU, similar to what GDB provides for C programming.

In light of such limitations of current debugging tools and great demand from the university’s Computer Organization course (where the majority of students have experienced debugging the CPU with LEDs or rewriting entire modules just to clear a single line or wrong code), our team set out to develop a comprehensive CPU debugger targeted pipelined CPUs for that course. 

We are working closely with the course’s lab professor for a release this semester and in doing so, playing an important role in the lab’s transition toward teaching pipelined CPU and RISC-V architecture.

## Stakeholders

There're 3 main stakeholders involved, all of which are of great importance:

- **Course students**: the main target users, being third-year undergraduates that have been through CPU design puts us in a good position to understand their exact needs.
- ******************************Course teachers and assistants******************************: the CPU debugger is projected to be incorporated into part of the lab teaching material about designing pipelined CPUs, hence teachers and assistants will have to understand its functions and operating manual to better guide students.
- ************************************Future maintainers************************************: this CPU debugger will be an open-source project to provide others in need with a tool and perhaps attract contributors to expand the debugger’s capabilities.

## Scope

Out CPU debugger is an application that is aimed to serve only one purpose, and do it well! That’s a very important goal as large applications with tons of unrelated features can only add complexity to development and cost time with little to no merit for the end user’s experience. 

The debugger will only provide functionalities related to debugging:

- Analyzing the `top.v` file and illustrating CPU module diagrams.
- Allows the user to specify the signals they want to check during CPU operation on a graphical interface (the module diagram generated).
- Providing UART transmission of instruction files to the CPU.
- Pausing the CPU anytime during execution while preserving the entire CPU’s state.
- Dynamically inserting breakpoints in the instruction file after transmitting the instruction file to the CPU.

Although some of these features might seem familiar as they are typically provided by mainstream IDEs (for example, JetBrains) or individual UART transmitters, putting them all together and implementing them on a hardware level is nevertheless challenging.

## Goal

There is one and only one goal of this project:

<aside>
<img src="https://www.notion.so/icons/target_red.svg" alt="https://www.notion.so/icons/target_red.svg" width="40px" /> Help students *identify errors* during CPU design more *efficiently*.

</aside>

The current greatly simplified user journey goes something like this:

1. Code the CPU using hardware description language such as Verilog, this typically involves implementing different modules with different functionalities.
2. Connect those modules with a top module (`top.v`), without an overall view of the intricate connections, it’s essentially gluing the CPU together with hope and prayers.
3. Write a test bench program for the CPU or individual model and analyze the simulated register or wire values to check correctness. (The simulation process is extremely slow!)
4. Write the instructions with another program (for example, Mars), and perhaps perform some limited debugging. (The IO of the CPU cannot be tested at this stage.)
5. With the assumption that all modules and the CPU is operating correctly, generate the bitstream and program the FPGA.
6. Without any guarantee that the instructions are going to run correctly, the instructions are also being written into the CPU’s onboard RAM. 
7. Some groups might devote time to incorporate a UART module to transmit the instructions through UART and not need to burn it every time instructions are changed.
8. Without any way for the instructions to indicate their operating state, the instructions are executed. 

There’s a catch in this procedure if the instructions and CPU are functioning correctly, then the IO can be used to perform debugging, but if there is any error and the IO is not working, nothing can be done to further locate the problem. So essentially almost everything has to work to enable onboard debugging.

With the CPU debugger, we strive to enable the following to-go user journey:

1. Code the CPU and interconnect the modules.
2. Use the debugger’s visualization feature to check the connections and overall design of the CPU.
3. Write instructions.
4. With a UART module built into the CPU, there’s no need to take time to do any integration.
5. Select signals for debugging and then program the FPGA with VIVADO.
6. Send instruction files directly to the CPU with the debugger.
7. Execute the instructions with the ability to pause, execute the next instruction, and run until the next breakpoint, all while being able to check in with all the signals specified previously.
8. For any bug identified through the signals, the corresponding modules or instructions can be easily identified and reexamined.

No more slow simulation, blindly connecting modules, and unknown bugs in the CPU.

## Requirements

********************Functional********************

- Illustrating CPU module diagrams.
- Sending instruction files to the CPU RAM.
- Pausing the CPU remotely.
- Execute the next instruction or execute until the next breakpoint.
- Display the value of signals at breakpoints during the instruction execution.
- Dynamic breakpoint insertion during instruction execution.
- Auto UART port selection.
- Users could revert to any page before the current page.

**None-functional**

- Illustration generation should be under 5s.
- The error rate of module diagram generation should be under 5%.
- The accuracy of instruction recognition should be above 90%.
- Support `.v` and `.asm` files.
- A user can learn to use the debugger within 30mins.
- Able to run on both macOS and Windows.

## Process

As the program is aimed to be put into commission before the Computer Organization project at the end of this semester, the team has decided to take on the highly flexible **evolutionary process model**. 

As the process is iterative, instead of developing different functions each at a time. multiple functions are all developed together, with basic functions implemented first and more refinements or adjustments later.

## Schedule

The debugger will probability undergo 3 revisions:

1. `rev0.9` (week 5): a bare Qt framework with some UI components available with QML
2. `rev1.0` (week 9): a working prototype without non-essential features, this will be constantly improved upon during beta testing among the students during their project
3. `rev1.1` (week 13): a complete debugger with all planned features implemented, hopefully with bugs ironed out

## Deliverables

**********************Milestone 2**********************

As milestone 2 is around the midterm, and it will take some time for the course professor to evaluate the debugger and perform beta testing for bugs later, the team is aiming to deliver a working debugger with limited capabilities at milestone 2 (signal selection, animations, and more non-crucial features will not be available).

**********Final**********

At the final milestone, the team will provide a fully-fledged CPU debugger, which would already be put into action as a tool for improving a pipelined CPU during the Computer Organization project. Together with open-source code, a user manual, a bare pipelined CPU (for students to have a good template to explore and develop upon), and development instructions for future contributions.
