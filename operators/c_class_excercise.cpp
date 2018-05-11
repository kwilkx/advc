#include <gtest/gtest.h>
#include <iostream>
#include <functional>

using namespace std;

namespace one {
class C {
public:
    C(const char* text) {
        table = new char[strlen(text) + 1];
        strcpy(table, text);
    }

    ~C() {
        delete[] table;
    }

    C& operator=(const C& other) {
        return *this;
    }

    C& operator=(C&& other) {

        return *this;
    }

    char* getStr() {
        return table;
    }

private:
    char* table;
};
}

namespace two {
template<typename T>
class C {
public:
    C(T* data, size_t size) {
        table = new T[size];
        memcpy(table, data, size);
        this->size = size;
    }
    ~C() {
        delete[] table;
    }

    C& operator=(const C& other) {
        return *this;
    }

    C& operator=(C&& other) {
        return *this;
    }
    char* getPtr() {
        return table;
    }

private:
    char* table;
    size_t size;
};
} //namespace two

TEST(C_class, copy_test) {
    one::C c1("this is a test");
    one::C c2("someting other");
    one::C c3("lets see if that works in case of longer string");
    one::C c4("bye!");

    EXPECT_STREQ(c1.getStr(), "this is a test");

    c1 = c2;
    EXPECT_STREQ(c1.getStr(), c2.getStr());

    c1 = c3;
    EXPECT_STREQ(c1.getStr(), c3.getStr());

    c1 = c4;
    EXPECT_STREQ(c1.getStr(), c4.getStr());
}

TEST(C_class, move_test) {
    one::C c1("this is a test");
    one::C c2("someting other");
    one::C c3("lets see if that works in case of longer string");
    one::C c4("bye!");

    EXPECT_STREQ(c1.getStr(), "this is a test");

    c1 = move(c2);
    EXPECT_STREQ(c1.getStr(), "someting other");
    EXPECT_EQ(c2.getStr(), nullptr);

    c1 = move(c3);
    EXPECT_STREQ(c1.getStr(),
            "lets see if that works in case of longer string");
    EXPECT_EQ(c3.getStr(), nullptr);

    c1 = move(c4);
    EXPECT_STREQ(c1.getStr(), "bye!");
    EXPECT_EQ(c4.getStr(), nullptr);
}
