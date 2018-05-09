#include <gtest/gtest.h>
#include <iostream>
#include <functional>

struct Shape {
    Shape() {
    }
    virtual double calculate() noexcept = 0;
    virtual ~Shape() {
    }
};

struct Rect: Shape {
    Rect(double a, double b) :
            _a(a), _b(b) {
    }
    virtual double calculate() noexcept override {
        return _a * _b;
    }
    virtual ~Rect() {
    }
private:
    double _a;
    double _b;
};

struct Circle: Shape {
    Circle(double r) :
            _r(r) {
    }
    virtual double calculate() noexcept override{
        return _r*_r*3.14;
    }
    virtual ~Circle(){};
private:
    double _r;
};
struct Triangle: Shape {
    virtual double calculate() noexcept override;
    virtual ~Triangle(){};
};

double calculateShapeArea(std::unique_ptr<Shape>& sp) {
    return sp->calculate();
}

TEST(calculateShapeArea, Rect) {
    std::unique_ptr<Shape> r = std::make_unique<Rect>(2, 6);
    EXPECT_EQ(calculateShapeArea(r), 12.);

    std::unique_ptr<Shape> c = std::make_unique<Circle>(3);
    EXPECT_EQ(calculateShapeArea(c), 28.26);
}

TEST(calculateShapeArea, two) {

}
