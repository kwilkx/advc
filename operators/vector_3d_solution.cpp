#include <gtest/gtest.h>

using namespace std;

template<typename T>
class Vector3d {
public:
    Vector3d(T x, T y, T z) :
            x_(x), y_(y), z_(z) {
    }
    Vector3d<T>& operator+=(const Vector3d<T>& rhs) {
        x_ += rhs.x_;
        y_ += rhs.y_;
        z_ += rhs.z_;
        return *this;
    }
    friend Vector3d<T> operator+(Vector3d<T> lhs, const Vector3d<T>& rhs) {
        lhs += rhs;
        return lhs;
    }

    T getX() {
        return x_;
    }
    T getY() {
        return y_;
    }
    T getZ() {
        return z_;
    }

//and continue
    //....

private:
    T x_;
    T y_;
    T z_;
};

TEST(vector_3d, add) {
    Vector3d<int> v1 { 1, 2, 3 };
    Vector3d<int> v2 { 100, 200, 300 };

    Vector3d<int> sum = v1 + v2;

    EXPECT_EQ(sum.getX(), 101);
    EXPECT_EQ(sum.getY(), 202);
    EXPECT_EQ(sum.getZ(), 303);

    sum += v1;

    EXPECT_EQ(sum.getX(), 102);
    EXPECT_EQ(sum.getY(), 204);
    EXPECT_EQ(sum.getZ(), 306);
}
