#pragma once
#include "Shape.h"

class myRectangle : public Shape {
protected:
    int height;
    int width;
    COLORREF fillColor;

public:
    myRectangle(int x = 0, int y = 0, int w = 0, int h = 0, int lw = 1, COLORREF lc = WHITE, COLORREF fc = BLACK) :
        Shape(x, y, lw, lc), height(h), width(w), fillColor(fc) {}

    void display() const override;

    void setFullColor(COLORREF fc) override;

    void draw() const override;

    void setHeight(int h);

    void setWidth(int w);

    COLORREF getFillColor() const override;

    void SaveToFile(ofstream& file) const override;
};