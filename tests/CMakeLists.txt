# Add Google Test
enable_testing()

# Add the test executable
add_executable(test_basicInterval ArithmeticPoints/Intervals/test_basicInterval.cpp)

# Link the test executable with Google Test and your project libraries
target_link_libraries(test_basicInterval gtest gtest_main pthread)

# Add tests
add_test(NAME BasicIntervalTest_ConstructorAndBounds COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.ConstructorAndBounds)
add_test(NAME BasicIntervalTest_ContainsValue COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.ContainsValue)
add_test(NAME BasicIntervalTest_ContainsInterval COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.ContainsInterval)
add_test(NAME BasicIntervalTest_IntersectsInterval COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.IntersectsInterval)
add_test(NAME BasicIntervalTest_Intersection COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.Intersection)
add_test(NAME BasicIntervalTest_Joint COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.Joint)
add_test(NAME BasicIntervalTest_DiscreteAndContinuous COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.DiscreteAndContinuous)
add_test(NAME BasicIntervalTest_FiniteAndInfinite COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.FiniteAndInfinite)
add_test(NAME BasicIntervalTest_EmptyInterval COMMAND test_basicInterval --gtest_filter=BasicIntervalTest.EmptyInterval)