#include <gtest/gtest.h>

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

template<typename Char> struct CustomStringFunctions {

    CustomStringFunctions() = default;
    CustomStringFunctions(const Char *ptr) {
        std::copy(ptr, ptr + std::strlen(ptr), std::back_inserter(_data));
    }
    CustomStringFunctions(const std::basic_string<Char> &str) {
        std::copy(std::begin(str), std::end(str), std::back_inserter(_data));
    }

    CustomStringFunctions(const CustomStringFunctions<Char>& rhs) {
        std::copy(std::begin(rhs._data), std::end(rhs._data),
                std::back_inserter(_data));
    }

    bool isEqual(const std::string &str) {
        std::string tmp;
        std::copy(std::begin(_data), std::end(_data), std::back_inserter(tmp));

        return tmp == str;
    }

    CustomStringFunctions& add(const CustomStringFunctions<Char>& other) {
        std::copy(std::begin(other._data), std::end(other._data),
                std::back_inserter(_data));
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
