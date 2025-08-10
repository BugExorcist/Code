#include "myRectangle.h"

void myRectangle::display() const {
    cout << "Rectangle" << endl;
    cout << "Height: " << height << endl;
    cout << "Width: " << width << endl;
    Shape::display();
    cout << "Fill Color: ";
    Shape::colorTranslation(static_cast<int>(fillColor)); cout << endl;
}

void myRectangle::setFullColor(COLORREF fc) {
    fillColor = fc;
}

void myRectangle::draw() const {
    setlinecolor(lineColor);
    setlinestyle(PS_SOLID, (int)lineWidth);
    setfillcolor(fillColor);
    if (fillColor == BLACK)
        rectangle(posX, posY, posX + width, posY + height);
    else
        fillrectangle(posX, posY, posX + width, posY + height);
}

void myRectangle::setHeight(int h) {
    height = h;
}

void myRectangle::setWidth(int w) {
    width = w;
}

COLORREF myRectangle::getFillColor() const {
    return fillColor;
}

void myRectangle::SaveToFile(ofstream& file) const {
    int type = 2;  // 代表矩形
    file.write(reinterpret_cast<const char*>(&type), sizeof(int));  // 写入形状类型
    file.write(reinterpret_cast<const char*>(&posX), sizeof(int));
    file.write(reinterpret_cast<const char*>(&posY), sizeof(int));
    file.write(reinterpret_cast<const char*>(&height), sizeof(int));
    file.write(reinterpret_cast<const char*>(&width), sizeof(int));
    file.write(reinterpret_cast<const char*>(&lineWidth), sizeof(int));
    file.write(reinterpret_cast<const char*>(&lineColor), sizeof(COLORREF));
    file.write(reinterpret_cast<const char*>(&fillColor), sizeof(COLORREF));
}