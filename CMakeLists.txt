cmake_minimum_required(VERSION 3.17.3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g" CACHE STRING "Default CXX options" FORCE)
project(sfedu_ictis_ap_dsa)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)


add_executable(sfedu_ictis_ap_dsa main.cpp Array.cpp tests/Tests.h tests/Tests.cpp Array.h Array.cpp tests/TestData.h tests/ArrayTestImpl.h performance-tests/PerformanceTests.cpp performance-tests/PerformanceTests.h Array.cpp Stack.cpp List.cpp List.h Queue.cpp Queue.h Array.cpp List.cpp)
