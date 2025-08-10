#include "myRectangle.h"

void myRectangle::display() const {
    cout << "Rectangle " << endl;
    Shape::display();
    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;
}

void myRectangle::draw() const {
    setlinecolor(lineColor);
    setlinestyle(PS_SOLID, (int)lineWidth);
    rectangle(posX, posY, posX + width, posY + height);
}

void myRectangle::setHeight(double h) {
    height = h;
}

void myRectangle::setWidth(double w) {
    width = w;
}