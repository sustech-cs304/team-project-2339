cmake_minimum_required(VERSION 3.0.0)
project(CPUDebugger VERSION 0.1.0)

include(CTest)
enable_testing()

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(CPUDebugger main.cpp)
target_link_libraries(CPUDebugger PRIVATE Qt6::Core)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
