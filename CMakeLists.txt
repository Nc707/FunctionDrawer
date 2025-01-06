cmake_minimum_required(VERSION 3.10)

project(FunctionDrawer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

file(GLOB SOURCES 
"src/*.cpp" 
"src/*.h" 
"src/Expressions/*.h"
"src/Expressions/Operations/*.h"
"src/Expressions/Operations/binaryOperations/*.cpp"
"src/Expressions/Operations/unaryOperations/*.cpp"
"src/Expressions/Operations/unaryOperations/trigonometricOperations/*.cpp"
"src/Expressions/Operations/Strategies/*.h"
"src/Expressions/Operations/Strategies/binaryOperations/*.h"
"src/Expressions/Operations/Strategies/binaryOperations/basicOperations/*.h"
"src/Expressions/Operations/Strategies/unaryOperations/*.h"
"src/Expressions/Operations/Strategies/unaryOperations/trigonometricOperations/*.h"
"src/Expressions/Variables/*.cpp"
"src/Expressions/Variables/*.h"
"src/Expressions/Variables/Constants/*.h"
"src/Expressions/Variables/IndependentVariables/*.h"
)

add_executable(FunctionDrawer ${SOURCES})