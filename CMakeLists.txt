cmake_minimum_required(VERSION 2.8)

project(stack)

include_directories(include)


add_executable(Tests ${TESTS_SOURCE} tests/count.cpp tests/main.cpp tests/pop.cpp tests/push.cpp)
