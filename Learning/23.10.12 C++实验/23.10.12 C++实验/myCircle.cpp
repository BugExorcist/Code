#include "myCircle.h"

void myCircle::display() const {
    cout << "Circle " << endl;
    Shape::display();
    cout << "Radius: " << radius << endl;
}

void myCircle::draw() const {
    setlinecolor(lineColor);
    setlinestyle(PS_SOLID, (int)lineWidth);
    circle(posX, posY, radius);
}

void myCircle::setRadius(double r) {
    radius = r;
}

double myCircle::getRadius() const {
    return radius;
}