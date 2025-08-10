#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include "Shape.h"
#include "myCircle.h"
#include "myEllipse.h"
#include "myRectangle.h"
#include "myLine.h"
#include <fstream>

class Canvas {
private:
    vector<Shape*> Shapes;
    //定义几个画布中按钮的位置 参数分别是：x1 x2 y1 y2
    const int button11 = 0, button12 = 128, button13 = 480, button14 = 520;//圆形
    const int button21 = 128, button22 = 256, button23 = 480, button24 = 520;//矩形
    const int button31 = 256, button32 = 384, button33 = 480, button34 = 520;//椭圆
    const int button41 = 384, button42 = 512, button43 = 480, button44 = 520;//线段
    const int button51 = 512, button52 = 640, button53 = 480, button54 = 500;//线条颜色
    const int button61 = 512, button62 = 640, button63 = 500, button64 = 520;//填充颜色

    void buttonColor(int type, int x);

    void Refresh(int type, int lc, int fc, int px);

    COLORREF colorType(int x);
public:
    void addCircle(int x, int y, int r, int lw,COLORREF lf, COLORREF fc);

    void addEllipse(int x, int y, int rx, int ry, int lw, COLORREF lf, COLORREF fc);

    void addRectangle(int x, int y, int w, int h, int lw, COLORREF lf, COLORREF fc);
    
    void addLine(int x, int y, int x2, int y2, int lw, COLORREF lf);

    void deleteShape(int num);

    void displayShapes() const;

    void fillColor(int num, COLORREF fc);

    void drawShapes() const;

    int Size();

    ~Canvas();

    void mouseOperation(); //鼠标操作窗口

    void Save();

    void Load();

    void outputjpg();
};