#include <gtest/gtest.h>
#include "turkish.hpp"

TEST(test1, p) {
    int n = 0;
    ASSERT_TRUE(translationIntoTurkish(n) == "sifir");
}

TEST(test2, p) {
    int n = 1;
    ASSERT_TRUE(translationIntoTurkish(n) == "bir");
}

TEST(test3, p) {
    int n = 40;
    ASSERT_FALSE(translationIntoTurkish(n) == "elli");
}

TEST(test4, p) {
    int n = 70;
    ASSERT_TRUE(translationIntoTurkish(n) == "yetmiş");
}

TEST(test5, p) {
    int n = 13;
    ASSERT_FALSE(translationIntoTurkish(n) == "yirmi yedi");
}

TEST(test6, p) {
    int n = 13;
    ASSERT_TRUE(translationIntoTurkish(n) == "on üç");
}

TEST(test7, p) {
    int n = 94;
    ASSERT_TRUE(translationIntoTurkish(n) == "doksan dört");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}