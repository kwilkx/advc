#include <gtest/gtest.h>
#include <iostream>
#include <functional>

using namespace std;

class C {
public:
    C(const char* text) {
        table = new char[strlen(text) + 1];
        strcpy(table, text);
    }

    ~C() {
        delete [] table;
    }

    C& operator=(const C& other)
    {
        return *this;
    }
    C& operator=(C&& other)
    {
        return *this;
    }

    char* getStr() {
        return table;
    }

private:
    char* table;
};

TEST(C_class, copy_test) {
    C c1("this is a test");
    C c2("someting other");
    C c3("lets see if that works in case of longer string");
    C c4("bye!");

    EXPECT_STREQ(c1.getStr(), "this is a test");

    c1 = c2;
    EXPECT_STREQ(c1.getStr(), c2.getStr());

    c1 = c3;
    EXPECT_STREQ(c1.getStr(), c3.getStr());

    c1 = c4;
    EXPECT_STREQ(c1.getStr(), c4.getStr());
}

TEST(C_class, move_test) {
    C c1("this is a test");
    C c2("someting other");
    C c3("lets see if that works in case of longer string");
    C c4("bye!");

    EXPECT_STREQ(c1.getStr(), "this is a test");

    c1 = move(c2);
    EXPECT_STREQ(c1.getStr(), "someting other");
    EXPECT_EQ(c2.getStr(), nullptr);

    c1 = move(c3);
    EXPECT_STREQ(c1.getStr(), "lets see if that works in case of longer string");
    EXPECT_EQ(c3.getStr(), nullptr);

    c1 = move(c4);
    EXPECT_STREQ(c1.getStr(), "bye!");
    EXPECT_EQ(c4.getStr(), nullptr);
}
