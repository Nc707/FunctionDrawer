cmake_minimum_required(VERSION 3.10)

project(FunctionDrawer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(src)

# Gather all source files (only .cpp files)
file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "src/ArithmeticPoints/*.cpp"
    "src/ArithmeticPoints/Expressions/*.cpp"
    "src/ArithmeticPoints/Expressions/Operations/*.cpp"
    "src/ArithmeticPoints/Expressions/Operations/Strategies/*.cpp"
    "src/ArithmeticPoints/Expressions/Operations/Strategies/binaryOperations/*.cpp"
    "src/ArithmeticPoints/Expressions/Operations/Strategies/binaryOperations/basicOperations/*.cpp"
    "src/ArithmeticPoints/Expressions/Operations/Strategies/unaryOperations/*.cpp"
    "src/ArithmeticPoints/Expressions/Operations/Strategies/unaryOperations/trigonometricOperations/*.cpp"
    "src/ArithmeticPoints/Expressions/Variables/*.cpp"
    "src/ArithmeticPoints/Expressions/Variables/Constants/*.cpp"
    "src/ArithmeticPoints/Expressions/Variables/IndependentVariables/*.cpp"
    "src/ArithmeticPoints/Factories/*.cpp"
    "src/ArithmeticPoints/PointsGenerators/2DGenerators/*.cpp"
    "src/ArithmeticPoints/PointsGenerators/3DGenerators/*.cpp"
)

add_executable(FunctionDrawer ${SOURCES})