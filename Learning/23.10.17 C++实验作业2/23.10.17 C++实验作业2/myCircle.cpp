#include "myCircle.h"

void myCircle::display() const {
    cout << "Circle" << endl;
    cout << "Radius: " << radius << endl;
    Shape::display();
    cout << "Fill Color: ";
    Shape::colorTranslation(static_cast<int>(fillColor)); cout << endl;
}

void myCircle::setFullColor(COLORREF fc) {
    fillColor = fc;
}

void myCircle::draw() const {
    setlinecolor(lineColor);
    setlinestyle(PS_SOLID, (int)lineWidth);
    setfillcolor(fillColor);
    if (fillColor == BLACK)
        circle(posX, posY, radius);
    else
        fillcircle(posX, posY, radius);
}

void myCircle::setRadius(int r) {
    radius = r;
}

int myCircle::getRadius() const {
    return radius;
}

COLORREF myCircle::getFillColor() const {
    return fillColor;
}

void myCircle::SaveToFile(std::ofstream& file) const {
    int type = 1;  // 代表圆形
    file.write(reinterpret_cast<const char*>(&type), sizeof(int));  // 写入形状类型
    file.write(reinterpret_cast<const char*>(&posX), sizeof(int));
    file.write(reinterpret_cast<const char*>(&posY), sizeof(int));
    file.write(reinterpret_cast<const char*>(&radius), sizeof(int));
    file.write(reinterpret_cast<const char*>(&lineWidth), sizeof(int));
    file.write(reinterpret_cast<const char*>(&lineColor), sizeof(COLORREF));
    file.write(reinterpret_cast<const char*>(&fillColor), sizeof(COLORREF));
}