#include <gtest/gtest.h>
#include "Three.hpp"

TEST(test1, copy) {
    Three num1("12");
    Three num2(num1);
    ASSERT_TRUE(num1 == num2);
}

TEST(test2, assignment) {
    Three num1({'1', '0', '2', '1'});
    Three num2 = num1;
    ASSERT_TRUE(num1 == num2);
}

TEST(test3, equal1) {
    Three num1("120");
    Three num2({'1', '2', '0'});
    ASSERT_TRUE(num1 == num2);
}

TEST(test4, equal2) {
    Three num1("1220");
    Three num2({'2', '2', '1', '0'});
    ASSERT_FALSE(num1 == num2);
}

TEST(test5, not_equal1) {
    Three num1("1202");
    Three num2({'2', '0', '1', '2'});
    ASSERT_TRUE(num1 != num2);
}

TEST(test6, not_equal2) {
    Three num1("1022");
    Three num2({'1', '0', '2', '2'});
    ASSERT_FALSE(num1 != num2);
}

TEST(test7, less) {
    Three num1("10");
    Three num2({'1', '0', '2'});
    ASSERT_TRUE(num1 < num2);
}

TEST(test8, less_equal) {
    Three num1("12020");
    Three num2({'1', '2'});
    ASSERT_FALSE(num1 <= num2);
}


TEST(test10, more_equal) {
    Three num1("11");
    Three num2({'1', '1'});
    ASSERT_TRUE(num1 >= num2);
}

TEST(test11, addition) {
    Three num1("12");
    Three num2({'1', '1'});
    ASSERT_TRUE((num1 + num2) == Three("100"));
}

TEST(test12, substraction1) {
    Three num1("22");
    Three num2({'2'});
    ASSERT_TRUE((num1 - num2) == Three("20"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}