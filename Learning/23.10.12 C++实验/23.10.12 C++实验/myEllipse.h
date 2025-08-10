#pragma once
#include "Shape.h"

class myEllipse : public Shape {
protected:
    double posRX;
    double posRY;

public:
    myEllipse(double x = 0, double y = 0, double rx = 0, double ry = 0, double lw = 1, COLORREF lc = WHITE) :
        Shape(x, y, lw, lc), posRX(rx), posRY(ry) {}

    void display() const override;

    void draw() const override;

    void setRightPos(double x, double y);
};