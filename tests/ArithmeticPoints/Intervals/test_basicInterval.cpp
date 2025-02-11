#include <gtest/gtest.h>
#include "../src/ArithmeticPoints/Intervals/basicInterval.h"

TEST(BasicIntervalTest, ConstructorAndBounds) {
    ArithmeticPoints::BasicInterval<int> interval(1, 10);
    EXPECT_EQ(interval.getLowerBound(), 1);
    EXPECT_EQ(interval.getUpperBound(), 10);
    EXPECT_TRUE(interval.isLowerClosed());
    EXPECT_TRUE(interval.isUpperClosed());
    EXPECT_FALSE(interval.isLowerInfinite());
    EXPECT_FALSE(interval.isUpperInfinite());
}

TEST(BasicIntervalTest, ContainsValue) {
    ArithmeticPoints::BasicInterval<int> interval(1, 10);
    EXPECT_TRUE(interval.contains(5));
    EXPECT_FALSE(interval.contains(0));
    EXPECT_FALSE(interval.contains(11));
}

TEST(BasicIntervalTest, ContainsInterval) {
    auto interval1 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(1, 10);
    auto interval2 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(2, 5);
    auto interval3 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(0, 5);
    EXPECT_TRUE(interval1->contains(interval2));
    EXPECT_FALSE(interval2->contains(interval1));
    EXPECT_FALSE(interval1->contains(interval3));

    // Test with infinite intervals
    auto interval4 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(1, 10, true, true, false, true);
    auto interval5 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(5, std::numeric_limits<int>::max(), true, false, false, true);
    EXPECT_TRUE(interval4->contains(interval5));
    EXPECT_FALSE(interval5->contains(interval4));

    // Test with discrete intervals
    auto interval6 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(5);
    auto interval7 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(5, 5, true, true, false, false);
    EXPECT_TRUE(interval6->contains(interval7));
    EXPECT_TRUE(interval7->contains(interval6));
}
TEST(BasicIntervalTest, OpenAndClosedEndings) {
    // Closed interval
    ArithmeticPoints::BasicInterval<int> closedInterval(1, 10, true, true);
    EXPECT_TRUE(closedInterval.contains(1));
    EXPECT_TRUE(closedInterval.contains(10));

    // Open interval
    ArithmeticPoints::BasicInterval<int> openInterval(1, 10, false, false);
    EXPECT_FALSE(openInterval.contains(1));
    EXPECT_FALSE(openInterval.contains(10));

    // Half-open intervals
    ArithmeticPoints::BasicInterval<int> leftOpenInterval(1, 10, false, true);
    EXPECT_FALSE(leftOpenInterval.contains(1));
    EXPECT_TRUE(leftOpenInterval.contains(10));

    ArithmeticPoints::BasicInterval<int> rightOpenInterval(1, 10, true, false);
    EXPECT_TRUE(rightOpenInterval.contains(1));
    EXPECT_FALSE(rightOpenInterval.contains(10));
}
TEST(BasicIntervalTest, MixedOpenClosedInfiniteDiscrete) {
    // Infinite interval with closed lower bound and open upper bound
    ArithmeticPoints::BasicInterval<int> infiniteClosedOpen(1, std::numeric_limits<int>::max(), true, false, false, true);
    EXPECT_TRUE(infiniteClosedOpen.contains(1));
    EXPECT_TRUE(infiniteClosedOpen.contains(std::numeric_limits<int>::max()));

    ArithmeticPoints::BasicInterval<int> infiniteClosedOpen2(1, 5, true, false, false, false);
    EXPECT_TRUE(infiniteClosedOpen2.contains(1));
    EXPECT_FALSE(infiniteClosedOpen2.contains(5));

    // Infinite interval with open lower bound and closed upper bound
    ArithmeticPoints::BasicInterval<int> infiniteOpenClosed(std::numeric_limits<int>::min(), 10, false, true, true, false);
    EXPECT_TRUE(infiniteOpenClosed.contains(std::numeric_limits<int>::min()));
    EXPECT_TRUE(infiniteOpenClosed.contains(10));

    ArithmeticPoints::BasicInterval<int> infiniteOpenClosed2(5, 10, false, true, false, false);
    EXPECT_FALSE(infiniteOpenClosed2.contains(5));
    EXPECT_TRUE(infiniteOpenClosed2.contains(10));

    // Discrete interval with closed bounds
    ArithmeticPoints::BasicInterval<int> discreteClosed(5, 5, true, true, false, false);
    EXPECT_TRUE(discreteClosed.contains(5));
    EXPECT_FALSE(discreteClosed.contains(4));
    EXPECT_FALSE(discreteClosed.contains(6));

    // Discrete interval with open bounds
    ArithmeticPoints::BasicInterval<int> discreteOpen(5, 10, false, false, false, false);
    EXPECT_FALSE(discreteOpen.contains(5));
    EXPECT_FALSE(discreteOpen.contains(10));

}
TEST(BasicIntervalTest, IntersectsInterval) {
    // Test with discrete intervals
    auto interval1 = std::make_shared<ArithmeticPoints::BasicInterval<double>>(1, 10);
    auto interval2 = std::make_shared<ArithmeticPoints::BasicInterval<double>>(5, 15);
    auto interval3 = std::make_shared<ArithmeticPoints::BasicInterval<double>>(11, 20);
    EXPECT_TRUE(interval1->intersects(interval2));
    EXPECT_FALSE(interval1->intersects(interval3));

    // Test with infinite intervals
    auto interval4 = std::make_shared<ArithmeticPoints::BasicInterval<double>>(1, 10, true, true, false, false);
    auto interval5 = std::make_shared<ArithmeticPoints::BasicInterval<double>>(11, 20, false, true, true, false);
    EXPECT_TRUE(interval4->intersects(interval5));
}

TEST(BasicIntervalTest, Intersection) {
    auto interval1 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(1, 10);
    auto interval2 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(5, 15);
    std::shared_ptr<ArithmeticPoints::Interval<int>> intersection = interval1->intersection(interval2);
    EXPECT_EQ(intersection->getLowerBound(), 5);
    EXPECT_EQ(intersection->getUpperBound(), 10);
}

TEST(BasicIntervalTest, Joint) {
    auto interval1 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(1, 10);
    auto interval2 = std::make_shared<ArithmeticPoints::BasicInterval<int>>(5, 15);
    std::shared_ptr<ArithmeticPoints::Interval<int>> joint = interval1->joint(interval2);
    EXPECT_EQ(joint->getLowerBound(), 1);
    EXPECT_EQ(joint->getUpperBound(), 15);
}

TEST(BasicIntervalTest, DiscreteAndContinuous) {
    ArithmeticPoints::BasicInterval<int> interval1(5);
    ArithmeticPoints::BasicInterval<int> interval2(1, 10);
    EXPECT_TRUE(interval1.isDiscrete());
    EXPECT_FALSE(interval2.isDiscrete());
    EXPECT_FALSE(interval1.isContinuous());
    EXPECT_TRUE(interval2.isContinuous());
}

TEST(BasicIntervalTest, FiniteAndInfinite) {
    ArithmeticPoints::BasicInterval<int> interval1(1, 10);
    ArithmeticPoints::BasicInterval<int> interval2(1, 10, true, true, true, false);
    EXPECT_TRUE(interval1.isFinite());
    EXPECT_FALSE(interval2.isFinite());
    EXPECT_FALSE(interval1.isInfinite());
    EXPECT_TRUE(interval2.isInfinite());
}

TEST(BasicIntervalTest, EmptyInterval) {
    ArithmeticPoints::BasicInterval<int> interval1(1, 1, false, false);
    ArithmeticPoints::BasicInterval<int> interval2(1, 1, true, true);
    EXPECT_TRUE(interval1.isEmpty());
    EXPECT_FALSE(interval2.isEmpty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}