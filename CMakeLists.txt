cmake_minimum_required(VERSION 3.10)

project(FunctionDrawer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# Add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

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
    "src/ArithmeticPoints/Intervals/*.cpp"
)

# Add the main executable
add_executable(FunctionDrawer ${SOURCES})

# Add the test executable
add_executable(test_basicInterval tests/ArithmeticPoints/Intervals/test_basicInterval.cpp)

# Link the test executable with Google Test and your project libraries
target_link_libraries(test_basicInterval ${GTEST_LIBRARIES} pthread)

# Add tests
add_test(NAME BasicIntervalTest_ConstructorAndBounds COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.ConstructorAndBounds)
add_test(NAME BasicIntervalTest_ContainsValue COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.ContainsValue)
add_test(NAME BasicIntervalTest_ContainsInterval COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.ContainsInterval)
add_test(NAME BasicIntervalTest_OpenAndClosedEndings COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.OpenAndClosedEndings)
add_test(NAME BasicIntervalTest_MixedOpenClosedInfiniteDiscrete COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.MixedOpenClosedInfiniteDiscrete)
add_test(NAME BasicIntervalTest_IntersectsInterval COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.IntersectsInterval)
add_test(NAME BasicIntervalTest_Intersection COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.Intersection)
add_test(NAME BasicIntervalTest_Joint COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.Joint)
add_test(NAME BasicIntervalTest_DiscreteAndContinuous COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.DiscreteAndContinuous)
add_test(NAME BasicIntervalTest_FiniteAndInfinite COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.FiniteAndInfinite)
add_test(NAME BasicIntervalTest_EmptyInterval COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.EmptyInterval)