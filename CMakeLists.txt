cmake_minimum_required(VERSION 3.20)
project(team_2339)

set(CMAKE_CXX_STANDARD 17)

#include_directories(CDebuggerTest)
#include_directories(codes)
#include_directories(codes/CPU_Debugger)
#include_directories(codes/CPU_Debugger/Controllers)
#include_directories(codes/CPU_Debugger/Lib_Comm)
#include_directories(codes/CPU_Debugger/States)
#include_directories(codes/view)
include_directories(CPUDebugger)
#include_directories(CPUDebugger/File)
#include_directories(CPUDebugger/controller)
#include_directories(CPUDebugger/model)
#include_directories(CPUDebugger/model/compile)
#include_directories(CPUDebugger/uart)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/Applications/Qt/6.4.2/macos/lib/cmake")

find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Quick REQUIRED)

add_executable(team_2339
#        CDebuggerTest/tst_model.cpp
#        codes/CPU_Debugger/Controllers/BackendController.cpp
#        codes/CPU_Debugger/Controllers/BackendController.h
#        codes/CPU_Debugger/Lib_Comm/comm.cpp
#        codes/CPU_Debugger/Lib_Comm/comm.h
#        codes/CPU_Debugger/States/DebugginState.cpp
#        codes/CPU_Debugger/States/DebugginState.h
#        codes/CPU_Debugger/States/State.cpp
#        codes/CPU_Debugger/States/State.h
#        codes/CPU_Debugger/States/WaitingState.cpp
#        codes/CPU_Debugger/States/WaitingState.h
#        codes/CPU_Debugger/main.cpp
#        codes/CPU_Debugger/mainwindow.cpp
#        codes/CPU_Debugger/mainwindow.h
#        codes/view/QML_STUDY/main.cpp
#        CPUDebugger/controller/FileController.cpp
#        CPUDebugger/controller/FileController.h
#        CPUDebugger/model/compile/compiler.cpp
#        CPUDebugger/model/compile/compiler.h
#        CPUDebugger/model/compile/global_compile.cpp
#        CPUDebugger/model/compile/global_compile.h
#        CPUDebugger/model/compile/MAlex.cpp
#        CPUDebugger/model/compile/MAlex.h
        CPUDebugger/File/AsmFile.h
        CPUDebugger/File/AsmFile.cpp
        CPUDebugger/File/DebugFile.h
        CPUDebugger/File/DebugFile.cpp
        CPUDebugger/File/CoeFile.h
        CPUDebugger/File/CoeFile.cpp
        #        CPUDebugger/model/FFile.cpp
#        CPUDebugger/model/FFile.h
#        CPUDebugger/model/FileInputFactory.cpp
#        CPUDebugger/model/FileInputFactory.h
#        CPUDebugger/model/FileOutputFactory.h
#        CPUDebugger/model/FileStore.cpp
#        CPUDebugger/model/FileStore.h
#        CPUDebugger/model/Module.h
#        CPUDebugger/model/ModuleData.h
#        CPUDebugger/model/CPUSignal.h
#        CPUDebugger/model/TopVFileInputFactory.cpp
#        CPUDebugger/model/TopVFileInputFactory.h
#        CPUDebugger/model/VFile.cpp
#        CPUDebugger/model/VFile.h
#        CPUDebugger/uart/CoreGenerator.cpp
#        CPUDebugger/uart/CoreGenerator.h
#        CPUDebugger/main.cpp
#        CPUDebugger/uart/CoreGenerator.cpp
#        CPUDebugger/uart/CoreGenerator.h
        )

target_link_libraries(team_2339 Qt6::Core)
target_link_libraries(team_2339 Qt6::Widgets)
target_link_libraries(team_2339 Qt6::Quick)
