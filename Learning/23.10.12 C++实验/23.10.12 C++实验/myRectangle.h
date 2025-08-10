#pragma once
#include "Shape.h"

class myRectangle : public Shape {
protected:
    double height;
    double width;

public:
    myRectangle(double x = 0, double y = 0, double w = 0, double h = 0, double lw = 1, COLORREF lc = WHITE) :
        Shape(x, y, lw, lc), height(h), width(w) {}

    void display() const override;

    void draw() const override;

    void setHeight(double h);

    void setWidth(double w);
};