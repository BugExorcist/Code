#include "Shape.h"

void Shape::display() const  {
    cout << "Position: (" << posX << ", " << posY << ")" << endl;
    cout << "Line Width: " << lineWidth << endl;
    cout << "Line Color: ";
    Shape::colorTranslation(static_cast<int>(lineColor)); cout << endl;
}

void Shape::setPos(int x, int y) {
    posX = x;
    posY = y;
}

void Shape::setLineWidth(int lw) {
    lineWidth = lw;
}

void Shape::setlineColor(COLORREF lc) {
    lineColor = lc;
}

int Shape::getPosX() const {
    return posX;
}

int Shape::getPosY() const {
    return posY;
}

int Shape::getLineWidth() const {
    return lineWidth;
}

COLORREF Shape::getLineColor() const {
    return lineColor;
}

void Shape::colorTranslation(int x) const {
    if (x == 0)
        cout << "��";
    else if (x == 0xAA0000)
        cout << "��";
    else if (x == 0x00AA00)
        cout << "��";
    else if (x == 0xAAAA00)
        cout << "��";
    else if (x == 0x0000AA)
        cout << "��";
    else if (x == 0xAA00AA)
        cout << "��";
    else if (x == 0x0055AA)
        cout << "��";
    else if (x == 0x555555)
        cout << "��";
    else if (x == 0x55FFFF)
        cout << "��";
    else if (x == 0xFFFFFF)
        cout << "��";
}
