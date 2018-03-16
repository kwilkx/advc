#include <algorithm>
#include <array>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <functional>

// heap - sterta - vector
// stack - stos - array

template<std::size_t N, typename T, bool use_heap>
struct Array {
    Array()
             {

    }

    Array(const std::initializer_list<T> &init) {

    }

    T &operator[](std::size_t index) {

    }

    const T &operator[](std::size_t index) const {

    }

    T min() const {

    }

    T max() const {

    }

private:
    std::vector<T> _vector;
    std::array<T, N> _array;
};

TEST(Array, empty_array_is_zero_initialized) {
    Array<10, int, false> stack;
    EXPECT_EQ(stack[0], 0);

    Array<10, int, true> heap;
    EXPECT_EQ(heap[0], 0);
}

TEST(Array, stack_simple) {
    Array<10, int, false> stack;
    stack[5] = 10;
    EXPECT_EQ(stack[5], 10);
}

TEST(Array, heap_simple) {
    Array<10, int, true> heap;

    heap[5] = 10;
    EXPECT_EQ(heap[5], 10);
}

TEST(Array, array_stack_initialized) {
    Array<3, std::string, false> stack { "", "empty", "ttt" };
    EXPECT_TRUE(stack[0].empty());
    EXPECT_EQ(stack[2], "ttt");
}

TEST(Array, min_max) {
    Array<3, int, false> stack { 3, 5, 8 };
    EXPECT_EQ(stack.max(),8);
    EXPECT_EQ(stack.min(),3);
}

TEST(Array, array_stack_initialized_incorrect) {
    auto fn = []() {Array<1, std::string, false> stack {"", "empty", "ttt"};};

    EXPECT_ANY_THROW(fn());
}
