#include <gtest/gtest.h>
#include <iostream>
#include <functional>

namespace one {
template<typename T>
void minElement(T* array, std::size_t size, std::function<void(double)> fp) {

}
}  // namespace one

namespace two {
template<typename T>
void minElement(T array[], std::size_t size, std::function<void(double)> fp) {

}
}  // namespace two

TEST(MinElement, one) {

    double flag { };
    std::array<double, 5> d { 9, 1, 2, 3, 4 };
    std::function<void(double)> fp = [&](const double& d) {
        std::cout << "From lambda: " << d << std::endl;
        flag = d;
    };

    one::minElement(d.data(), 0, fp);
    EXPECT_EQ(flag, 0);

    one::minElement(d.data(), d.size(), fp);
    EXPECT_EQ(flag, 1);

}

TEST(MinElement, two) {

    double flag { };
    float array[] = { 7, 1, 2, 3, 4, 5, 6 };
    std::function<void(float)> fp = [&](const double& d) {
        std::cout << "From lambda: " << d << std::endl;
        flag = d;
    };

    two::minElement(array, 0, fp);
    EXPECT_EQ(flag, 0);

    two::minElement(array, 7, fp);
    EXPECT_EQ(flag, 1);
}
