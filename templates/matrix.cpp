#include <algorithm>
#include <array>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

template<std::size_t N, std::size_t M, typename T>
struct Matrix {
    Matrix() {
        if (N == 0) {
            throw std::underflow_error { "number of rows is 0" };
        }
        if (M == 0) {
            throw std::underflow_error { "number of columns is 0" };
        }
    }

    template<std::size_t N1, std::size_t M1, typename T1>
    Matrix(const Matrix<N1, M1, T1>& other) {
        if (N1 > N) {
            throw std::range_error { "number of rows error" };
        }
        if (M1 > M) {
            throw std::range_error { "number of columns error" };
        }
        for (size_t n = 0; n < N1; ++n) {
            for (size_t m = 0; m < M1; ++m) {
                _array[n][m] = other[n][m];
            }
        }
    }

    std::array<T, M> &operator[](std::size_t index) {
        return _array.at(index);
    }

    const std::array<T, M> &operator[](std::size_t index) const {
        return _array.at(index);
    }

    //10
    template<std::size_t N1, std::size_t M1, typename T1>
    friend std::ostream &operator<<(std::ostream &os,
            const Matrix<N1, M1, T1> &);

private:
    std::array<std::array<T, M>, N> _array{} ;
}
;

//10
template<std::size_t N, std::size_t M, typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<N, M, T> &matrix) {
    for (const auto &element : matrix._array) {
        for (const auto &e : element) {
            os << e;
        }
        os << endl;
    }
    return os;
}

//12.6
template<std::size_t N, std::size_t M>
struct Matrix<N, M, bool> {
    Matrix() {
        throw std::bad_typeid { };
    }
};

/*
template<typename T>
struct Matrix<0, 0, T> {
    Matrix() = delete;
};
template<std::size_t N, typename T>
struct Matrix<N, 0, T> {
    Matrix()=delete;
};
template<std::size_t M, typename T>
struct Matrix<0, M, T> {
    Matrix()=delete;
};
*/

TEST(TemplateMatrix, create) {
    Matrix<3, 5, int> m;
    EXPECT_EQ(m[0][0], 0);
    m[2][1] = 1;
    EXPECT_EQ(m[2][1], 1);
}

TEST(TemplateMatrix, createZero) {
    auto l = []() {
        Matrix<0, 3, int> m;
    };
    EXPECT_THROW(l(), underflow_error);

    auto l2 = []() {
        Matrix<3, 0, int> m;
    };
    EXPECT_THROW(l2(), underflow_error);
}

TEST(TemplateMatrix, createBool) {
    auto l = []() {
        Matrix<3, 3, bool> m;
    };
    EXPECT_THROW(l(), bad_typeid);
}

TEST(TemplateMatrix, copyCtor) {
    int number = 0;
    const int I = 2;
    const int J = 3;

    Matrix<I, J, int> m;
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            m[i][j] = ++number;
        }
    }

    Matrix<I, J, int> n = m;

    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            EXPECT_EQ(m[i][j], n[i][j]);
        }
    }
}
TEST(TemplateMatrix, copyCtorCopy) {
    int number = 0;
    const int I = 2;
    const int J = 2;

    Matrix<I, J, int> m;
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            m[i][j] = ++number;
        }
    }
    Matrix<3, 3, int> n = m;
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            EXPECT_EQ(m[i][j], n[i][j]);
        }
    }
}

TEST(TemplateMatrix, copyCtorExcept) {
    auto l = [&]() {
        Matrix<3, 3, int> m;
        m[1][1] = 5;
        Matrix<2, 3, int> n = m;
    };
    EXPECT_THROW(l(), range_error);
    auto o = [&]() {
        Matrix<3, 3, int> m;
        m[1][1] = 5;
        Matrix<3, 2, int> n = m;
    };
    EXPECT_THROW(o(), range_error);
}
