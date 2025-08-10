#pragma once
#include "Shape.h"

class myLine : public Shape {
private:
    int X2, Y2;

public:
    myLine(int x = 0, int y = 0, int x2 = 0, int y2 = 0, int lw = 1, COLORREF lc = WHITE) :
        Shape(x, y, lw, lc), X2(x2), Y2(y2) {}

    void display() const override;
    
    void setFullColor(COLORREF fc) override;

    void draw() const override;

    void setSecondPos(int x, int y);

    COLORREF getFillColor() const override;

    void SaveToFile(ofstream& file) const override;
};