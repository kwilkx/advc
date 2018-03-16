#include <gtest/gtest.h>

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>


template <typename Char> struct CustomStringOperators {

  template <typename T>
  friend bool operator==(const CustomStringOperators<T> &custom, const std::string &str);

  CustomStringOperators() = default;
  CustomStringOperators(const Char *ptr) {
    std::copy(ptr, ptr + std::strlen(ptr), std::back_inserter(_data));
  }

  CustomStringOperators(const std::basic_string<Char> &str) {
    std::copy(std::begin(str), std::end(str), std::back_inserter(_data));
  }

  CustomStringOperators(const CustomStringOperators<Char>& rhs)
  {
      std::copy(std::begin(rhs._data), std::end(rhs._data), std::back_inserter(_data));
  }

  CustomStringOperators& operator += (const CustomStringOperators<Char>& other)
  {
      std::copy(std::begin(other._data), std::end(other._data), std::back_inserter(_data));
      return *this;
  }

private:
  std::vector<Char> _data;
};

template <typename T>
bool operator==(const CustomStringOperators<T> &custom, const std::string &str) {
  std::string tmp;
  std::copy(std::begin(custom._data), std::end(custom._data),
            std::back_inserter(tmp));

  return tmp == str;
}

TEST(CustomStringOperators, emptyString) {
  CustomStringOperators<char> str;
  EXPECT_EQ(str, "");
}

TEST(CustomStringOperators, init_from_const_char) {
  CustomStringOperators<char> str{"this is a char"};
  EXPECT_EQ(str, "this is a char");
}

TEST(CustomStringOperators, init_from_basic_string) {
  CustomStringOperators<char> str{"this is a char"};
  EXPECT_EQ(str, "this is a char");
}

TEST(CustomStringOperators, plus_assign_operator) {
  CustomStringOperators<char> str{"t"};
  str += CustomStringOperators<char> { "i"};
  EXPECT_EQ(str, "ti");
}
TEST(CustomStringOperators, copyctor) {
  CustomStringOperators<char> str{"this is a str"};
  auto k = str;
  EXPECT_EQ(k, "this is a str");
}
