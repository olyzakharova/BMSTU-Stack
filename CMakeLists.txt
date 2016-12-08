cmake_minimum_required(VERSION 2.8)

project(stack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(TESTS_SOURCE tests/count.cpp tests/main.cpp tests/pop.cpp tests/push.cpp tests/catch.hpp )
set(SOURCE_FILES include/stack.hpp)

install (DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include  DESTINATION include)

include_directories(include)
add_executable(Tests ${TESTS_SOURCE} tests/count.cpp tests/main.cpp tests/pop.cpp tests/push.cpp)
