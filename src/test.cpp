#include <random>
#include "gtest/gtest.h"

#include "solution.cpp"

void CheckArray(const std::vector<int>& array) {
    auto [left, right] = GetRangeWithNullSum(array);

    int sum = 0;
    ASSERT_NE(left, NOT_EXISTED);
    ASSERT_NE(right, NOT_EXISTED);
    ASSERT_GE(left, 0);
    ASSERT_LE(left, right);
    ASSERT_LT(right, array.size());
    for (size_t i = left; i <= right; i++) {
        sum += array[i];
    }

    ASSERT_TRUE(sum % array.size() == 0);
}

TEST(Unit, JustWorks) {
    CheckArray({42});
    CheckArray({13, 14});
    CheckArray({12, 13});
    CheckArray({12, 14});
    CheckArray({13, 15});
    CheckArray({1, 2, 3});
    CheckArray({0, 2, 0});
    CheckArray({5, 73, 3, 1});
    CheckArray({12, 57, 13, 32, 14});
}

TEST(Unit, EqualElements) {
    std::vector<int> arr1(15, 0);
    CheckArray(arr1);
    std::vector<int> arr2(15, 42);
    CheckArray(arr2);
}



void TestRandomArrays(size_t array_size, size_t iterations_count) {
    std::vector<int> array(array_size);
    for (size_t i = 0; i < iterations_count; i++) {
        for (auto& x: array) {
            x = random() % 1'000'000 + 1;
        }
        CheckArray(array);
    }
}

TEST(Stress, EqualsElements) {
    std::vector<int> arr1(998'732, 0);
    CheckArray(arr1);
    std::vector<int> arr2(1'000'000, 42);
    CheckArray(arr2);
}

TEST(Stress, Random1) {
    TestRandomArrays(3, 100'000);
}

TEST(Stress, Random2) {
    TestRandomArrays(20, 100'000);
}

TEST(Stress, Random3) {
    TestRandomArrays(100, 100'000);
}

TEST(Stress, Random4) {
    TestRandomArrays(1000, 10'000);
}

TEST(Stress, Random5) {
    TestRandomArrays(10'000, 1000);
}

TEST(Stress, Random6) {
    TestRandomArrays(100'000, 100);
}

TEST(Stress, Random7) {
    TestRandomArrays(1'000'000, 10);
}
