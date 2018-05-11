#include <gtest/gtest.h>
#include <list>

using namespace std;

template<typename T>
struct Vector {
    std::list<T> mList;
    T& operator[](std::size_t idx) {
        auto it = mList.begin();
        for (size_t i = 0; i < mList.size(); ++i, ++it) {
            if (idx == i) {
                return *it;
            }
        }
        return *it;
    }
    const T& operator[](std::size_t idx) const {
        // return mVector[idx];
    }

    Vector<T> operator++() {
        for (auto& e : mList) {
            ++e;
        }
        return *this;
    }
};

template<class T>
std::ostream& operator <<(std::ostream& os, const std::list<T>& v) {
    os << "[";
    for (auto& el : v) {
        os << " " << el;
    }
    os << " ]";
    return os;
}

template<class T>
std::ostream& operator <<(std::ostream& os, const std::vector<T>& v) {
    os << "[";
    for (auto& el : v) {
        os << " " << el;
    }
    os << " ]";
    return os;
}

template<class T>
std::ostream& operator <<(std::ostream& os, const Vector<T>& v) {
    os << "[";
    for (auto& el : v.mList) {
        os << " " << el;
    }
    os << " ]";
    return os;
}

TEST(stream_operator, out) {

}
