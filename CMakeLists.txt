cmake_minimum_required(VERSION 2.8)
project(Apricot_Linear_Library)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCE_FILES src/*.cpp)
file(GLOB INCLUDE_FILES include/*.h)
include_directories(include/)
add_executable(apricot src/main.cpp ${SOURCE_FILES} ${INCLUDE_FILES})
