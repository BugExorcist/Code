#pragma once
#include "Shape.h"

class myEllipse : public Shape {
protected:
    int posRX;
    int posRY;
    COLORREF fillColor;

public:
    myEllipse(int x = 0, int y = 0, int rx = 0, int ry = 0, int lw = 1, COLORREF lc = WHITE, COLORREF fc = BLACK) :
        Shape(x, y, lw, lc), posRX(rx), posRY(ry),fillColor(fc) {}

    void display() const override;

    void setFullColor(COLORREF fc) override;

    void draw() const override;

    void setRightPos(int x, int y);

    COLORREF getFillColor() const override;

    void SaveToFile(ofstream& file) const override;
};