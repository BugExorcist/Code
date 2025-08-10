#include "Shape.h"

void Shape::display() const  {
    cout << "Position: (" << posX << ", " << posY << ")" << endl;
    cout << "Line Width: " << lineWidth << endl;
}

void Shape::setPos(double x, double y) {
    posX = x;
    posY = y;
}

void Shape::setLineWidth(double lw) {
    lineWidth = lw;
}

void Shape::setlineColor(COLORREF lc) {
    lineColor = lc;
}

double Shape::getPosX() const {
    return posX;
}

double Shape::getPosY() const {
    return posY;
}

double Shape::getLineWidth() const {
    return lineWidth;
}

COLORREF Shape::getFillColor() const {
    return lineColor;
}