#include "myLine.h"

void myLine::display() const {
    cout << "Line" << endl;
    Shape::display();
    cout << "End Pos��" << X2 << "��" << Y2 << "��" << endl;
}

void myLine::setFullColor(COLORREF fc) {
    cout << "�߶��޷������ɫ��" << endl;
}

void myLine::draw() const {
    setlinecolor(lineColor);
    setlinestyle(PS_SOLID, (int)lineWidth);
    line(posX, posY, X2, Y2);
}

void myLine::setSecondPos(int x, int y) {
    X2 = x;
    Y2 = y;
}

COLORREF myLine::getFillColor() const {
    //�����
    return 0;
}

void myLine::SaveToFile(ofstream& file) const {
    int type = 4;  // �����߶�
    file.write(reinterpret_cast<const char*>(&type), sizeof(int));  // д����״����
    file.write(reinterpret_cast<const char*>(&posX), sizeof(int));
    file.write(reinterpret_cast<const char*>(&posY), sizeof(int));
    file.write(reinterpret_cast<const char*>(&X2), sizeof(int));
    file.write(reinterpret_cast<const char*>(&Y2), sizeof(int));
    file.write(reinterpret_cast<const char*>(&lineWidth), sizeof(int));
    file.write(reinterpret_cast<const char*>(&lineColor), sizeof(COLORREF));
}