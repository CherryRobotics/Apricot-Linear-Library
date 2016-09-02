cmake_minimum_required(VERSION 3.5)
project(Apricot_Linear_Library)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    apricotMatrix.cpp
    apricotMatrix.h
    apricotVector.cpp
    apricotVector.h
    main.cpp)

add_executable(Apricot_Linear_Library ${SOURCE_FILES})