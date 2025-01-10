cmake_minimum_required(VERSION 3.10)

project(FunctionDrawer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(src)

# Gather all source files (only .cpp files)
file(GLOB SOURCES 
    "src/Factories/*.cpp"
    "src/*.cpp"
    "src/Expressions/*.cpp"
    "src/Expressions/Operations/*.cpp"
    "src/Expressions/Operations/Strategies/*.cpp"
    "src/Expressions/Operations/Strategies/binaryOperations/*.cpp"
    "src/Expressions/Operations/Strategies/binaryOperations/basicOperations/*.cpp"
    "src/Expressions/Operations/Strategies/unaryOperations/*.cpp"
    "src/Expressions/Operations/Strategies/unaryOperations/trigonometricOperations/*.cpp"
    "src/Expressions/Variables/*.cpp"
    "src/Expressions/Variables/Constants/*.cpp"
    "src/Expressions/Variables/IndependentVariables/*.cpp"
    "src/Factories/*.cpp"
    "src/PointsGenerators/2DGenerators/*.cpp"
    "src/PointsGenerators/3DGenerators/*.cpp"
)

add_executable(FunctionDrawer ${SOURCES})