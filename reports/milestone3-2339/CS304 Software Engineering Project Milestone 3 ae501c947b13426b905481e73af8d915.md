# CS304 Software Engineering Project Milestone 3

## Metrics

The statistical results of the metrics mentions in the requirements are shown in the following figure. These results are reached by combining `git` commands, `python` scripts and `bash` scripts together.

![metrics.png](CS304%20Software%20Engineering%20Project%20Milestone%203%20ae501c947b13426b905481e73af8d915/metrics.png)

Due to our development being in C++ and the definition of several modules in QT, it is difficult to define a "package" on top of this. Therefore, the "Number of packages" is missing in the aforementioned statistics. 

As for the "Number of 3rd party dependencies" item, it is difficult for us to directly track it in chronological order through our scripts. We not only rely on some external libraries developed by QT (managed through QT Maintenance), but also use external software that is unrelated to QT (Graphviz and Yosys). Since we do not use git to manage the latter, it is impossible to trace the time when they were added. If we include the third-party libraries provided by QT, then the total number of third-party libraries that our project depends on is 6 (Qquick, Qquickcontrols2, Qgui-private, Qserialport, Graphviz, Yosys).

## Documentation

Two separate sets of documentation are provided:

- Documentation for users is provided through the Notion platform, while a copy of it is available under the `documentations/User Manual` directory in the repo.
    
    [User Manual](https://idavid2619.notion.site/User-Manual-a13ae98fb90945508aec981ec1b6f57c)
    
    The user documentation is meant to be updated manually by developers, and will not be automated.
    
- Documentation for developers is aimed at helping developers to get an understanding of the project without needing to go through all the code and look up comments. The dev docs are hosted on Read the Docs (together with popular projects such as OP-TEE).
    
    [CPUDebugger Developer Documentation — CPUDebugger  documentation](https://cpudebugger.readthedocs.io/en/latest/)
    
    The developer documentation will be automatically updated upon commits using a webhook and a series of scripts. 
    
    It undergoes the workflow of: Doxygen → Sphinx → Exhale → Breath, where Doxygen is first used to generate comprehensive documentation with respect to the comments. Then Sphinx and it plugins, Exhale and Breath, are used to reformat the old-style (for example, the style used by OpenCV) Doxygen generated HTML to a Read the Docs style static webpage.
    
    This combination of Doxygen and Sphinx enables the team to continuously deliver up-to-date dev docs that are extremely comprehensive while having the flexibility of being able to integrate with future external documentations and at the same time be good to the eyes.
    

## Testing

**************Technology**************

We use `Google Test` to test our project. Besides, we use `gcovr` to generate our coverage report. It is sad that our project can only be tested partly. The reason is that our project combines software and hardware. The hardware part can be executed only when the computer is connected with FPGA. 

Here is the url for our test source code:

[team-project-2339/CGoogleTest at main · sustech-cs304/team-project-2339](https://github.com/sustech-cs304/team-project-2339/tree/main/CGoogleTest)

Here is snapshot of the test coverage report:

![Untitled](CS304%20Software%20Engineering%20Project%20Milestone%203%20ae501c947b13426b905481e73af8d915/Untitled.png)

`DebugController.cpp, AsmFile.cpp, DebugStore.cpp, comm.cpp, sender.cpp, sender.h, myobject1.cpp` is connected with hardware part, it is difficult to test without FPGA. 

**Detailed steps for hardware testing**:

1. A fixed testing use ASM file will be imported into the Block memories (RAM and ROM).
2. The `top_testbench.v` file is used for simulation, which contains an automated UART simulation function that can be used by the tester to specify which UART signals will be received by the CPU.
3. Execute simulation on Vivado.
4. Observe the waveforms and the binary values of a selected group of wires, registers, and memory locations to determine whether the CPU is responding according as designed.
5. Upon passing the testbench, the CPU will be implemented and the generated bitstream will be programed into the FPGA.
6. A COM port communicator will be used to perform preliminary tests, which will simply send opcodes to the CPU and observe the received results.
7. After passing the COM test, the PC Client will be started to test the integration of the UART communication class.
8. If the UART class behaves as expected, then the entire debug stage will be tested against a predefined ASM file (which has a loop).
9. Breakpoint setting, instruction highlight, CPU remote controlling, and ASM transmission will be tested at this stage.
10. The system will be concluded as passing if it passes all the above testing stages.

## Building

*qmake* is used to build our project.

qmake is a Simplicity and Cross-platform building tool. Powered by a proper  .pro file, qmake can detect developer’s system environment and generate building scripts automatedly.

In a *qmake* workflow, such commands is processed:

*qmake*:

```jsx
qmake: qmake.exe CGoogleTest.pro
```

*make*:

```jsx
cd build
make
```

MakeFile generated by qmake is following:

[Makefile](CS304%20Software%20Engineering%20Project%20Milestone%203%20ae501c947b13426b905481e73af8d915/Makefile.txt)

## Deployment

Containerization is difficult for our project. Since `Vivado` is only provided in Windows, only windows users needs to be considered in our project. It can be seemed that `CPUDebugger` is the tool for Verilog and assembler language(MIPS here in our project). The executable file is supported. 

`windeployqt` is used in our process of deployment. The dependency is the Qt environment can be easily migrated by `windeployqt`.

We have deployed our project in GitHub. You can install the package and click the executable file to run the project directory.  

In out repo, a beta version is released. You can find it in our github repo.

[Release First Release · sustech-cs304/team-project-2339](https://github.com/sustech-cs304/team-project-2339/releases/tag/v1.0.0-beta)

## GitHub Workflow

### Commit Standards of Our Project

- Commit messages should follow the Angular convention. It is recommended to use the Commitizen plugin in VSCode.
- Each commit should focus on making small and focused changes whenever possible.
- Ensure that the source code can compile, run, and pass tests before making a commit.
- Binary files are not allowed to be committed without permission, and personal configuration files should not be committed.
- All modifications for new features should be done in a `feature-branch` (lowercase letters and hyphens), while bug fixes should be done in a `hotfix-branch`. Once the changes are reviewed and approved, a merge request should be made to merge the changes into the `develop` branch. The merging of changes into the `develop` branch should be done by an administrator.
- After `develop` been tested, it will be merged into `main`.
- Commit provided by non-administrator will be ignored

### CI/CD

Continuous integration and deployment is achieved with Jenkins. Which uses a declarative pipeline and the xUnit plugin is used to display the Google Test results.

```groovy
#!/usr/bin/env groovy
pipeline {
    stages {
        stage("Build") {
            steps {
                qmake: qmake.exe CGoogleTest.pro
                Make: mingw32-make.exe -j16 in .\build-CGoogleTest-Desktop_Qt_6_4_3_MinGW_64_bit-Release
            }
        }
        stage("Test") {
            steps {
                CPUDebugger --gtest_output=xml:gtestresults.xml
            }
        }
    }
    post {
        always {
            xunit (
                thresholds: [ skipped(failureThreshold: '0'), failed(failureThreshold: '0') ],
                tools: [ GoogleTest(pattern: 'reports/*.xml') ]
            )
        }
    }
}
```

This is invoked with a periodic Github poll of 5-minute interval.