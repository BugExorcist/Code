#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <graphics.h>
using namespace std;

class Shape {
protected:
    double posX, posY;
    double lineWidth;
    COLORREF lineColor;

public:
    Shape(double x = 0, double y = 0, double lw = 1, COLORREF lc = WHITE) :
        posX(x), posY(y), lineWidth(lw), lineColor(lc) {}

    virtual void display() const = 0;

    virtual void draw() const = 0;

    virtual void setPos(double x, double y);

    virtual void setLineWidth(double lw);

    virtual void setlineColor(COLORREF lc);

    virtual double getPosX() const;

    virtual double getPosY() const;

    virtual double getLineWidth() const;

    virtual COLORREF getFillColor() const;
};