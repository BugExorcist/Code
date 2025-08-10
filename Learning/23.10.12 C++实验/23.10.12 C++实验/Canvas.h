#pragma once
#include "Shape.h"
#include "myCircle.h"
#include "myEllipse.h"
#include "myRectangle.h"

class Canvas {
private:
    vector<Shape*> shapes;

public:
    void addCircle(double x, double y, double r, double lw,COLORREF lf);

    void addEllipse(double x, double y, double rx, double ry, double lw, COLORREF lf);

    void addRectangle(double x, double y, double w, double h, double lw, COLORREF lf);

    void displayShapes() const;

    void drawShapes() const;

    ~Canvas();
};