cmake_minimum_required(VERSION 3.10)

project(FunctionDrawer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

file(GLOB SOURCES 
"src/*.cpp" 
"src/*.h" 
"src/Operations/*.cpp" 
"src/Operations/*.h"
"src/Variables/*.cpp"
"src/Variables/*.h"
)

add_executable(FunctionDrawer ${SOURCES})