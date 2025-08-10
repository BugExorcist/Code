#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <graphics.h>
#include <fstream>
#include <cstdlib>
using namespace std;

class Shape {
protected:
    int posX, posY;
    int lineWidth;
    COLORREF lineColor;

public:
    Shape(int x = 0, int y = 0, int lw = 1, COLORREF lc = WHITE) :
        posX(x), posY(y), lineWidth(lw), lineColor(lc) {}

    virtual void display() const;

    virtual void draw() const = 0;

    virtual void setFullColor(COLORREF fc) = 0;

    void setPos(int x, int y);

    void setLineWidth(int lw);

    void setlineColor(COLORREF lc);

    int getPosX() const;

    int getPosY() const;

    int getLineWidth() const;

    COLORREF getLineColor() const;

    virtual COLORREF getFillColor() const = 0;

    void colorTranslation(int x) const;

    virtual void SaveToFile(std::ofstream& file) const = 0;
};