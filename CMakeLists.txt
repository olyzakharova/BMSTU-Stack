cmake_minimum_required(VERSION 2.8.7)

project(Stack)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

option(BUILD_SHARED_LIBS "Build shared instead of static library" OFF)
option(BUILD_TESTS "Build tests for stack" ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)
add_executable(Tests ${TEST_SOURCES} tests/main.cpp tests/push.cpp tests/pop.cpp tests/count.cpp)
   
