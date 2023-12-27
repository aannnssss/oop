#include <gtest/gtest.h>

#include "list.hpp"

int Factorial(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return n * Factorial(n - 1);
}

TEST(MapTest, MapKeysVal) {
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>, 10> > map;
    for (int i = 0; i < 10; ++i) {
        map[i] = Factorial(i);
    }
    int i = 0;
    for (const auto& p : map) {
        EXPECT_EQ(p.first, i);
        EXPECT_EQ(p.second, Factorial(i));
        ++i;
    }
}

TEST(ListTest, Empty) {
    List<int, Allocator<std::pair<const int, int>, 10> > list;
    list.PushBack(2);
    EXPECT_TRUE(!list.IsEmpty());
}


TEST(ListTest, Insert) {
    List<int, Allocator<std::pair<const int, int>, 10> > list;
    list.PushBack(2);
    list.PushBack(4);
    list.Insert(list.begin(), 1);
    list.Insert(list.end(), 3);
    EXPECT_EQ(list.Size(), 4);
    EXPECT_EQ(list.Head(), 1);
    EXPECT_EQ(list.Tail(), 4);
}

TEST(ListFunctional, Erase) {
    List<int, Allocator<std::pair<const int, int>, 10> > list;
    list.PushBack(44);
    list.PushBack(13);
    list.PushBack(8);
    list.Erase(list.begin());
    EXPECT_EQ(list.Size(), 2);
    EXPECT_EQ(list.Head(), 13);
    EXPECT_EQ(list.Tail(), 8);
}

TEST(ListTest, Clear) {
    List<int, Allocator<std::pair<const int, int>, 10> > list;
    list.PushBack(10);
    list.PushBack(560);
    list.Clear();
    EXPECT_TRUE(list.IsEmpty());
}

TEST(IteratorTest, Increment) {
    List<int, Allocator<std::pair<const int, int>, 10> > list;
    list.PushBack(5);
    list.PushBack(99);
    auto iter = list.begin();
    EXPECT_EQ(*iter, 5);
    ++iter;
    EXPECT_EQ(*iter, 99);
}

TEST(IteratorTest, EqualityInequality) {
    List<int, Allocator<std::pair<const int, int>, 10> > list;
    list.PushBack(123);
    auto iter1 = list.begin();
    auto iter2 = list.begin();
    EXPECT_TRUE(iter1 == iter2);
    ++iter1;
    EXPECT_TRUE(iter1 != iter2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
