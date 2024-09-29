cmake_minimum_required(VERSION 3.5.0)
project(ELEVATOR_SYS VERSION 0.1.0 LANGUAGES C CXX)

add_executable(ELEVATOR_SYS main.cpp passengerElevator.cpp serviceElevator.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")