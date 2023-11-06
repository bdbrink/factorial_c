// factorial_test.cpp
#include "gtest/gtest.h"
#include "factorial.cpp"

TEST(FactorialTest, ZeroAndOne) {
    EXPECT_EQ(factorial(0), 1);
    EXPECT_EQ(factorial(1), 1);
}

TEST(FactorialTest, PositiveNumbers) {
    EXPECT_EQ(factorial(5), 120); // 5! = 120
    EXPECT_EQ(factorial(10), 3628800); // 10! = 3628800
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
