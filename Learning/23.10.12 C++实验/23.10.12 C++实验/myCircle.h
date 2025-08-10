#pragma once
#include "Shape.h"

class myCircle : public Shape {
private:
    double radius;

public:
    myCircle(double x = 0, double y = 0, double r = 0, double lw = 1, COLORREF lc = WHITE) :
        Shape(x, y, lw, lc), radius(r) {}

    void display() const override;

    void draw() const override;

    void setRadius(double r);

    double getRadius() const;
};