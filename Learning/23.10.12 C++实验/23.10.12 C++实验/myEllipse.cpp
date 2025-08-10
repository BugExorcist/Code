#include "myEllipse.h"

void myEllipse::display() const {
    cout << "Ellipse " << endl;
    Shape::display();
    cout << "RightPosition: (" << posRX << ", " << posRY << ")" << endl;
}

void myEllipse::draw() const {
    setlinecolor(lineColor);
    setlinestyle(PS_SOLID, (int)lineWidth);
    ellipse(posX, posY, posRX, posRY);
}

void myEllipse::setRightPos(double x, double y) {
    posRX = x;
    posRY = y;
}