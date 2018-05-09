#include <gtest/gtest.h>
#include <iostream>

namespace one {
template<typename T>
T minElement(T* array, std::size_t size) {
    return {};
}
}  // namespace one

namespace two {
template<typename T>
T minElement(T array[], std::size_t size) {
    return {};
}
}  // namespace two

TEST(MinElement, one) {
    std::array<double, 5> d { 9, 1, 2, 3, 4 };
    EXPECT_EQ(one::minElement(d.data(), d.size()), 1);
}
TEST(MinElement, two) {
    float array[] = { 7, 1, 2, 3, 4, 5, 6 };
    EXPECT_EQ(two::minElement(array, 7), 1);
}
