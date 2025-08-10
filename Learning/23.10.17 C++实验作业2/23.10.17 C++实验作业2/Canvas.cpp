#include "Canvas.h"

void Canvas::addCircle(int x, int y, int r, int lw, COLORREF lf, COLORREF fc) {
    Shape* shape = new myCircle(x, y, r, lw, lf, fc);
    Shapes.push_back(shape);
}

void Canvas::addEllipse(int x, int y, int rx, int ry, int lw, COLORREF lf, COLORREF fc) {
    Shape* shape = new myEllipse(x, y, rx, ry, lw, lf, fc);
    Shapes.push_back(shape);
}

void Canvas::addRectangle(int x, int y, int w, int h, int lw, COLORREF lf, COLORREF fc) {
    Shape* shape = new myRectangle(x, y, w, h ,lw, lf, fc);
    Shapes.push_back(shape);
}

void Canvas::addLine(int x, int y, int x2, int y2, int lw, COLORREF lf) {
    Shape* shape = new myLine(x, y, x2, y2, lw, lf);
    Shapes.push_back(shape);
}

void Canvas::deleteShape(int num) {
    if (num == 0){
        while (Shapes.size() != 0) {
            int index = 0;
            delete Shapes[index];// 先删除元素
            Shapes.erase(Shapes.begin() + index);// 再删除索引
            --index; // 在删除元素后更新索引
            /*原本写成了
            delete Shapes[0];
            Shapes.erase(Shapes.begin());
            但是当删除一个元素后，Shapes的大小会减少，但是Shapes.begin()仍然指向被删除元素
            后面的那个元素。因此，如果你立即删除下一个元素，你可能会访问到无效的内存区域。
            正确的做法应该是先获取当前要删除元素的索引，然后再删除该元素。这样，你就可以确保
            不会访问到无效的内存区域。*/
        }
    }
    else {
        //delete Shapes[num - 1];
        delete Shapes[static_cast<uintptr_t>(num) - 1];
        //将num转换为uintptr_t类型，然后再进行减1操作，以确保不会触发警告。这样做可以消除警告，同时也确保了程序在释放内存时不会出现意外溢出。
        //uintptr_t 是 C/C++ 中定义的整数类型，用于存放指针值，它的大小足够容纳任意指针类型。
        Shapes.erase(Shapes.begin() + num - 1);
    }
}

void Canvas::displayShapes() const {
    for (size_t i = 0; i < Shapes.size(); i++) {
        cout << "Shape:" << i + 1 << endl;
        Shapes[i]->display();
        cout << endl;
    }
}

void Canvas::fillColor(int num, COLORREF fc) {
    Shapes[num - 1]->setFullColor(fc);
}

void Canvas::drawShapes() const {
    initgraph(640, 480);
    for (size_t i = 0; i < Shapes.size(); i++) {
        Shapes[i]->draw();
    }
    getchar();
    getchar();
    closegraph();
}

int Canvas::Size() {
    return Shapes.size();
}

Canvas::~Canvas() {
    for (const auto& shape : Shapes) {
        delete shape;
    }
    Shapes.clear();
}

void Canvas::buttonColor(int type, int x){
    setfillcolor(WHITE);
    setlinecolor(BLACK);
    if(type == x)
        setfillcolor(CYAN);
}

void Canvas::Refresh(int type, int lc, int fc, int px) {   //更新画布

    BeginBatchDraw(); //开始批量绘图 用来解决频闪问题，不过会带来延迟

    cleardevice();
    for (size_t i = 0; i < Shapes.size(); i++) {
        Shapes[i]->draw();
    }
    // 绘制按钮
    setlinestyle(PS_SOLID, 1);
    buttonColor(type, 0);
    fillrectangle(button11, button13, button12, button14);  // 按钮1
    buttonColor(type, 1);
    fillrectangle(button21, button23, button22, button24);  // 按钮2
    buttonColor(type, 2);
    fillrectangle(button31, button33, button32, button34);  // 按钮3
    buttonColor(type, 3);
    fillrectangle(button41, button43, button42, button44);  // 按钮4
    setlinecolor(BLACK);
    setfillcolor(colorType(lc));
    fillrectangle(button51, button53, button52, button54);  // 按钮5
    setfillcolor(colorType(fc));
    fillrectangle(button61, button63, button62, button64);  // 按钮6
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);//透明模式
    outtextxy(button11, 500, L"圆形");
    outtextxy(button21, 500, L"矩形");
    outtextxy(button31, 500, L"椭圆");
    outtextxy(button41, 500, L"线段");

    settextcolor(WHITE);//用来在画图窗口打印变量
    TCHAR s[5];
    _stprintf(s, _T("px:%d"), px);
    outtextxy(button11, 460, s);

    setbkmode(OPAQUE);//不透明模式
    outtextxy(button51, 480, L"线条颜色");
    outtextxy(button61, 500, L"填充颜色");

    EndBatchDraw(); //结束批量绘制
}

void Canvas::mouseOperation() {
    initgraph(640, 520);
    
    bool isDragging = false;
    int startX, startY, endX, endY;
    int shapeType = -1;  // 当前选中的形状类型，-1未选择
    int lc = 1, fc = 0, px = 1;//线条颜色 填充颜色 线条粗细（像素）
    Refresh(shapeType, lc, fc, px);

    while (true) {
        if (MouseHit()) {   // 监听鼠标事件
            MOUSEMSG msg = GetMouseMsg();

            if (msg.uMsg == WM_LBUTTONDOWN) {  // 鼠标左键按下
                if (msg.x >= button11 && msg.x <= button12 && msg.y >= button13 && msg.y <= button14)
                {
                    shapeType = 0;  // 按钮1的范围，表示圆形
                    startX = endX = 0;  //点击按钮时，初始化坐标点，防止切换图形时直接生成一个图形
                }
                else if (msg.x >= button21 && msg.x <= button22 && msg.y >= button23 && msg.y <= button24)
                {
                    shapeType = 1;  // 按钮2的范围，表示矩形
                    startX = endX = 0;
                }
                else if (msg.x >= button31 && msg.x <= button32 && msg.y >= button33 && msg.y <= button34)
                {
                    shapeType = 2;  // 按钮3的范围，表示椭圆形
                    startX = endX = 0;
                }
                else if (msg.x >= button41 && msg.x <= button42 && msg.y >= button43 && msg.y <= button44)
                {
                    shapeType = 3;  // 按钮4的范围，表示线段
                    startX = endX = 0;
                }
                else if (msg.x >= button51 && msg.x <= button52 && msg.y >= button53 && msg.y <= button54)
                {
                    lc++;  // 按钮5的范围，表示切换线条颜色
                    if (lc > 9)
                        lc = 1;
                    startX = endX = 0;
                }
                else if (msg.x >= button61 && msg.x <= button62 && msg.y >= button63 && msg.y <= button64)
                {
                    fc++;  // 按钮6的范围，表示切换填充颜色
                    if (fc > 9)
                        fc = 0;
                    startX = endX = 0;
                }
                else
                {
                    isDragging = true;// 鼠标按下且不在按钮范围内，表示开始拖动
                    startX = endX = msg.x;
                    startY = endY = msg.y;
                }
            }
            else if (msg.uMsg == WM_LBUTTONUP) {  // 鼠标左键释放
                isDragging = false;
                if (shapeType == 0 && startX != 0 && endX != 0)  // 圆形
                {
                    Shape* shape = new myCircle(startX, startY, max(abs(endX - startX), abs(endY - startY)), px, colorType(lc), colorType(fc));
                    Shapes.push_back(shape);
                }
                else if (shapeType == 1 && startX != 0 && endX != 0)  // 矩形
                {
                    Shape* shape = new myRectangle(startX, startY, (endX - startX), (endY - startY), px, colorType(lc), colorType(fc));
                    Shapes.push_back(shape);
                }
                else if (shapeType == 2 && startX != 0 && endX != 0)  // 椭圆
                {
                    Shape* shape = new myEllipse(startX, startY, endX, endY, px, colorType(lc), colorType(fc));
                    Shapes.push_back(shape);
                }
                else if (shapeType == 3 && startX != 0 && endX != 0)  // 线段
                {
                    Shape* shape = new myLine(startX, startY, endX, endY, px, colorType(lc));
                    Shapes.push_back(shape);
                }
                Refresh(shapeType, lc, fc, px);

            }
            else if (msg.uMsg == WM_MOUSEMOVE) {  // 鼠标移动
                if (isDragging) {
                    endX = msg.x;
                    endY = msg.y;
                    Refresh(shapeType, lc, fc, px);

                    BeginBatchDraw(); //开始批量绘图 用来解决频闪问题，不过会带来延迟
                    if (shapeType == 0)  // 圆形
                    {
                        myCircle tempShape(startX, startY, max(abs(endX - startX), abs(endY - startY)), px, colorType(lc), colorType(fc));
                        tempShape.draw();
                    }
                    else if (shapeType == 1)  // 矩形
                    {
                        myRectangle tempShape(startX, startY, (endX - startX), (endY - startY), px, colorType(lc), colorType(fc));
                        tempShape.draw();
                    }
                    else if (shapeType == 2)  // 椭圆
                    {
                        myEllipse tempShape(startX, startY, endX, endY, px, colorType(lc), colorType(fc));
                        tempShape.draw();
                    }
                    else if (shapeType == 3)  // 线段
                    {
                        myLine tempShape(startX, startY, endX, endY, px, colorType(lc));
                        tempShape.draw();
                    }
                    EndBatchDraw(); //结束批量绘制
                }
            }
        }

        if (_kbhit()) { //监听键盘事件
            //退出画布
            char ch = _getch();
            if (ch == 27) {  // 按下ESC键
                break;
            }
            else if (ch == '+') {
                if (px < 8) {
                    px++;
                }
            }
            else if (ch == '-') {
                if (px > 1) {
                    px--;
                }
            }
            //撤销
            else if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState('Z') & 0x8000) { // 检测Ctrl+Z组合键是否被按下
                deleteShape(Shapes.size());
            }
            Refresh(shapeType, lc, fc, px);
        }
        //Sleep(0.01);
    }
    FlushMouseMsgBuffer();
    closegraph();
}

COLORREF Canvas::colorType(int x) {
    switch (x)
    {
    case 0:
        return BLACK;
        break;
    case 1:
        return WHITE;
        break;
    case 2:
        return BLUE;
        break;
    case 3:
        return GREEN;
        break;
    case 4:
        return CYAN;
        break;
    case 5:
        return RED;
        break;
    case 6:
        return MAGENTA;
        break;
    case 7:
        return BROWN;
        break;
    case 8:
        return YELLOW;
        break;
    case 9:
        return DARKGRAY;
        break;
    default:
        break;
    }
}

void Canvas::Save() {
    string filename;
    cout << "输入想保存的文件名:(.txt结尾)\n>>>";
    cin >> filename;

    ofstream file(filename, ios::out | ios::binary);  // 使用 ofstream 来创建文件输出流，并以二进制模式打开
    for (const auto& shape : Shapes) {
        shape->SaveToFile(file);  // 多态调用 SaveToFile 函数
    }
    file.close();
}

void Canvas::Load() {
    std::string filename;
    std::cout << "输入要读取的文件名:(.txt结尾)\n>>>";
    std::cin >> filename;
    
    ifstream file(filename, ios::in | ios::binary);  // 使用 ifstream 来创建文件输入流，并以二进制模式打开
    if (!file) {
        cout << "无法打开文件" << endl;
        return;
    }
    while (true) {
        int type;
        file.read(reinterpret_cast<char*>(&type), sizeof(int));  // 读取形状类型
        if (file.eof()) break;  // 避免读取到文件结尾
        int posX, posY, radius, posX2, posY2, lineWidth;
        COLORREF lineColor, fillColor;
        if (type == 1) {  // 圆形
            file.read(reinterpret_cast<char*>(&posX), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY), sizeof(int));
            file.read(reinterpret_cast<char*>(&radius), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineWidth), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineColor), sizeof(COLORREF));
            file.read(reinterpret_cast<char*>(&fillColor), sizeof(COLORREF));
            Shapes.push_back(new myCircle(posX, posY, radius, lineWidth, lineColor, fillColor));
        }
        else if(type == 2) {  //矩形
            file.read(reinterpret_cast<char*>(&posX), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY), sizeof(int));
            file.read(reinterpret_cast<char*>(&posX2), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY2), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineWidth), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineColor), sizeof(COLORREF));
            file.read(reinterpret_cast<char*>(&fillColor), sizeof(COLORREF));
            Shapes.push_back(new myRectangle(posX, posY, posX2, posY2, lineWidth, lineColor, fillColor));
        }
        else if (type == 3) {  //椭圆
            file.read(reinterpret_cast<char*>(&posX), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY), sizeof(int));
            file.read(reinterpret_cast<char*>(&posX2), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY2), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineWidth), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineColor), sizeof(COLORREF));
            file.read(reinterpret_cast<char*>(&fillColor), sizeof(COLORREF));
            Shapes.push_back(new myEllipse(posX, posY, posX2, posY2, lineWidth, lineColor, fillColor));
        }
        else if (type == 4) {  //线段
            file.read(reinterpret_cast<char*>(&posX), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY), sizeof(int));
            file.read(reinterpret_cast<char*>(&posX2), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY2), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineWidth), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineColor), sizeof(COLORREF));
            Shapes.push_back(new myLine(posX, posY, posX2, posY2, lineWidth, lineColor));
        }
    }
    file.close();
}

void Canvas::outputjpg() {
    initgraph(640, 480);
    BeginBatchDraw(); //开始批量绘图
    for (size_t i = 0; i < Shapes.size(); i++) {
        Shapes[i]->draw();
    }
    EndBatchDraw(); //结束批量绘制
    IMAGE img;
    getimage(&img, 0, 0, 640, 480);

    saveimage(_T("output.jpg"), &img);
    closegraph();
    cout << "已保存为output.jpg\n按Enter继续...";
    getchar();
    getchar();
}
