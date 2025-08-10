#include "myEllipse.h"

void myEllipse::display() const {
    cout << "Ellipse" << endl;
    cout << "RightPosition: (" << posRX << ", " << posRY << ")" << endl;
    Shape::display();
    cout << "Fill Color: ";
    Shape::colorTranslation(static_cast<int>(fillColor)); cout << endl;
}

void myEllipse::setFullColor(COLORREF fc) {
    fillColor = fc;
}

void myEllipse::draw() const {
    setlinecolor(lineColor);
    setlinestyle(PS_SOLID, (int)lineWidth);
    setfillcolor(fillColor);
    if (fillColor == BLACK)
        ellipse(posX, posY, posRX, posRY);
    else
        fillellipse(posX, posY, posRX, posRY);
}

void myEllipse::setRightPos(int x, int y) {
    posRX = x;
    posRY = y;
}

COLORREF myEllipse::getFillColor() const {
    return fillColor;
}

void myEllipse::SaveToFile(ofstream& file) const {
    int type = 3;  // 代表椭圆
    file.write(reinterpret_cast<const char*>(&type), sizeof(int));  // 写入形状类型
    file.write(reinterpret_cast<const char*>(&posX), sizeof(int));
    file.write(reinterpret_cast<const char*>(&posY), sizeof(int));
    file.write(reinterpret_cast<const char*>(&posRX), sizeof(int));
    file.write(reinterpret_cast<const char*>(&posRY), sizeof(int));
    file.write(reinterpret_cast<const char*>(&lineWidth), sizeof(int));
    file.write(reinterpret_cast<const char*>(&lineColor), sizeof(COLORREF));
    file.write(reinterpret_cast<const char*>(&fillColor), sizeof(COLORREF));
}