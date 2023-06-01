cmake_minimum_required(VERSION 3.20)
set(PROJECT_NAME cgoogletest)
project(${PROJECT_NAME})

include(FetchContent)

FetchContent_Declare(googletest
                     GIT_REPOSITORY https://github.com/google/googletest
                     GIT_TAG v1.13.0)

FetchContent_Declare(yosys
                     GIT_REPOSITORY https://github.com/YosysHQ/yosys.git
                     GIT_TAG yosys-0.29)
#FetchContent_GetProperties(googletest)
#FetchContent_Populate(googletest)
#add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
FetchContent_Declare(webdot
                     GIT_REPOSITORY https://gitlab.com/graphviz/webdot.git
                     GIT_TAG b9e9acc7b0c775302cc57119606bd5643f5eee3b)

FetchContent_Declare(graphviz
                     GIT_REPOSITORY https://gitlab.com/graphviz/graphviz.git
                     GIT_TAG 8.0.5)

FetchContent_MakeAvailable(googletest webdot yosys graphviz)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/Applications/Qt/6.4.3/macos/lib/cmake")

include_directories(
        ../CPUDebugger
        ../CPUDebugger/File
        ../CPUDebugger/model
        ../CPUDebugger/controller
        ../CPUDebugger/Controllers
        ../CPUDebugger/debug
        ../CPUDebugger/parse-verilog
        ../CPUDebugger/Stores
        ../CPUDebugger/uart
        ../CPUDebugger/view
)

# find source files
file(GLOB_RECURSE SOURCE_FILES
     "${CMAKE_CURRENT_SOURCE_DIR}/../CPUDebugger/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

#message(${SOURCE_FILES})

find_package(
        Qt6 REQUIRED COMPONENTS
        Core
        Widgets
        Quick
        SerialPort
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(
        ${PROJECT_NAME}
        Qt6::Core
        Qt6::Widgets
        Qt6::Quick
        Qt6::SerialPort
        gtest_main
        gmock_main
)
