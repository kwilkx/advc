#include <gtest/gtest.h>

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

template<typename Char> struct CustomStringFunctions {

    CustomStringFunctions() = default;
    CustomStringFunctions(const Char *ptr) {
    }
    CustomStringFunctions(const std::basic_string<Char> &str) {
    }

    CustomStringFunctions(const CustomStringFunctions<Char>& rhs) {
    }

    bool isEqual(const std::string &str) {
        return false;
    }

    CustomStringFunctions& add(const CustomStringFunctions<Char>& other) {
        return *this;
    }

private:
    std::vector<Char> _data;
};

TEST(CustomStringFunctions, emptyString) {
    CustomStringFunctions<char> str;
    EXPECT_TRUE(str.isEqual(""));
}

TEST(CustomStringFunctions, init_from_const_char) {
    CustomStringFunctions<char> str { "this is a char" };
    EXPECT_TRUE(str.isEqual("this is a char"));
}

TEST(CustomStringFunctions, init_from_basic_string) {
    CustomStringFunctions<char> str { "this is a char" };
    EXPECT_TRUE(str.isEqual("this is a char"));
}

TEST(CustomStringFunctions, plus_assign_operator) {
    CustomStringFunctions<char> str { "t" };
    str.add(CustomStringFunctions<char> { "i" });
    EXPECT_TRUE(str.isEqual("ti"));
}
TEST(CustomStringFunctions, copyctor) {
    CustomStringFunctions<char> str { "this is a str" };
    auto k = str;
    EXPECT_TRUE(k.isEqual("this is a str"));
}
