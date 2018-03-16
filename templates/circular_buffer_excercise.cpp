#include <gtest/gtest.h>
#include <iostream>
#include <sstream>

#include <array>

template<typename T, std::size_t N>
struct CircularBuffer {

    template<typename T1, std::size_t N1>
    friend std::ostream &operator<<(std::ostream &os,
            const CircularBuffer<T1, N1> &);

    CircularBuffer() = default;
    CircularBuffer(const std::initializer_list<T> &list) {

    }

    const T &operator[](std::size_t index) const {
    }

    void push(const T &t) {

    }

    int size() {

    }

private:
    std::array<T, N> _data;
};

template<typename T, std::size_t N>
std::ostream &operator<<(std::ostream &os, const CircularBuffer<T, N> &buffer) {
    for (const auto &v : buffer._data)
        os << v;
    return os;
}

TEST(CircularBuffer, empty_buffer_is_zerod) {
    CircularBuffer<std::string, 10> buffer;
    EXPECT_TRUE(buffer[0].empty());
}

TEST(CircularBuffer, initialized_by_list) {
    CircularBuffer<std::string, 3> buffer { { "one", "two", "three" } };
    EXPECT_EQ(buffer[0], "one");
}

TEST(CircularBuffer, stream_operator) {
    CircularBuffer<std::string, 3> buffer { { std::string { "one" },
            std::string { "two" }, std::string { "three" } } };
    std::stringstream ss;
    ss << buffer;
    EXPECT_EQ(ss.str(), "onetwothree");
}

TEST(CircularBuffer, initialized_too_big) {
    auto fn = []() {
        CircularBuffer<std::string, 2> buffer { {"one", "two", "three"}};
    };
    EXPECT_ANY_THROW(fn());
}

TEST(CircularBuffer, small_buffer) {
    CircularBuffer<std::string, 2> buffer { "asd", "asd" };
    buffer.push("dd");
    buffer.push("bb");
    EXPECT_EQ(buffer[0], "dd");
    EXPECT_EQ(buffer[1], "bb");
}

TEST(CircularBuffer, size_check) {
    CircularBuffer<int, 2> buffer;
    EXPECT_EQ(buffer.size(), 0);
    buffer.push(1);
    EXPECT_EQ(buffer.size(), 1);
    buffer.push(2);
    EXPECT_EQ(buffer.size(), 2);
    buffer.push(3);
    EXPECT_EQ(buffer.size(), 2);
    buffer.push(4);
    EXPECT_EQ(buffer.size(), 2);
}
