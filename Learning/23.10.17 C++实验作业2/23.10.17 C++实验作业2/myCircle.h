#pragma once
#include "Shape.h"

class myCircle : public Shape {
private:
    int radius;
    COLORREF fillColor;

public:
    myCircle(int x = 0, int y = 0, int r = 0, int lw = 1, COLORREF lc = WHITE, COLORREF fc = BLACK) :
        Shape(x, y, lw, lc), radius(r), fillColor(fc) {}

    void display() const override;

    void setFullColor(COLORREF fc) override;

    void draw() const override;

    void setRadius(int r);

    int getRadius() const;

    COLORREF getFillColor() const override;

    void SaveToFile(ofstream& file) const override;
};