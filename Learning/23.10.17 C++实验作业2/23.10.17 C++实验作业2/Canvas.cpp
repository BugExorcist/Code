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
            delete Shapes[index];// ��ɾ��Ԫ��
            Shapes.erase(Shapes.begin() + index);// ��ɾ������
            --index; // ��ɾ��Ԫ�غ��������
            /*ԭ��д����
            delete Shapes[0];
            Shapes.erase(Shapes.begin());
            ���ǵ�ɾ��һ��Ԫ�غ�Shapes�Ĵ�С����٣�����Shapes.begin()��Ȼָ��ɾ��Ԫ��
            ������Ǹ�Ԫ�ء���ˣ����������ɾ����һ��Ԫ�أ�����ܻ���ʵ���Ч���ڴ�����
            ��ȷ������Ӧ�����Ȼ�ȡ��ǰҪɾ��Ԫ�ص�������Ȼ����ɾ����Ԫ�ء���������Ϳ���ȷ��
            ������ʵ���Ч���ڴ�����*/
        }
    }
    else {
        //delete Shapes[num - 1];
        delete Shapes[static_cast<uintptr_t>(num) - 1];
        //��numת��Ϊuintptr_t���ͣ�Ȼ���ٽ��м�1��������ȷ�����ᴥ�����档�����������������棬ͬʱҲȷ���˳������ͷ��ڴ�ʱ����������������
        //uintptr_t �� C/C++ �ж�����������ͣ����ڴ��ָ��ֵ�����Ĵ�С�㹻��������ָ�����͡�
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

void Canvas::Refresh(int type, int lc, int fc, int px) {   //���»���

    BeginBatchDraw(); //��ʼ������ͼ �������Ƶ�����⣬����������ӳ�

    cleardevice();
    for (size_t i = 0; i < Shapes.size(); i++) {
        Shapes[i]->draw();
    }
    // ���ư�ť
    setlinestyle(PS_SOLID, 1);
    buttonColor(type, 0);
    fillrectangle(button11, button13, button12, button14);  // ��ť1
    buttonColor(type, 1);
    fillrectangle(button21, button23, button22, button24);  // ��ť2
    buttonColor(type, 2);
    fillrectangle(button31, button33, button32, button34);  // ��ť3
    buttonColor(type, 3);
    fillrectangle(button41, button43, button42, button44);  // ��ť4
    setlinecolor(BLACK);
    setfillcolor(colorType(lc));
    fillrectangle(button51, button53, button52, button54);  // ��ť5
    setfillcolor(colorType(fc));
    fillrectangle(button61, button63, button62, button64);  // ��ť6
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);//͸��ģʽ
    outtextxy(button11, 500, L"Բ��");
    outtextxy(button21, 500, L"����");
    outtextxy(button31, 500, L"��Բ");
    outtextxy(button41, 500, L"�߶�");

    settextcolor(WHITE);//�����ڻ�ͼ���ڴ�ӡ����
    TCHAR s[5];
    _stprintf(s, _T("px:%d"), px);
    outtextxy(button11, 460, s);

    setbkmode(OPAQUE);//��͸��ģʽ
    outtextxy(button51, 480, L"������ɫ");
    outtextxy(button61, 500, L"�����ɫ");

    EndBatchDraw(); //������������
}

void Canvas::mouseOperation() {
    initgraph(640, 520);
    
    bool isDragging = false;
    int startX, startY, endX, endY;
    int shapeType = -1;  // ��ǰѡ�е���״���ͣ�-1δѡ��
    int lc = 1, fc = 0, px = 1;//������ɫ �����ɫ ������ϸ�����أ�
    Refresh(shapeType, lc, fc, px);

    while (true) {
        if (MouseHit()) {   // ��������¼�
            MOUSEMSG msg = GetMouseMsg();

            if (msg.uMsg == WM_LBUTTONDOWN) {  // ����������
                if (msg.x >= button11 && msg.x <= button12 && msg.y >= button13 && msg.y <= button14)
                {
                    shapeType = 0;  // ��ť1�ķ�Χ����ʾԲ��
                    startX = endX = 0;  //�����ťʱ����ʼ������㣬��ֹ�л�ͼ��ʱֱ������һ��ͼ��
                }
                else if (msg.x >= button21 && msg.x <= button22 && msg.y >= button23 && msg.y <= button24)
                {
                    shapeType = 1;  // ��ť2�ķ�Χ����ʾ����
                    startX = endX = 0;
                }
                else if (msg.x >= button31 && msg.x <= button32 && msg.y >= button33 && msg.y <= button34)
                {
                    shapeType = 2;  // ��ť3�ķ�Χ����ʾ��Բ��
                    startX = endX = 0;
                }
                else if (msg.x >= button41 && msg.x <= button42 && msg.y >= button43 && msg.y <= button44)
                {
                    shapeType = 3;  // ��ť4�ķ�Χ����ʾ�߶�
                    startX = endX = 0;
                }
                else if (msg.x >= button51 && msg.x <= button52 && msg.y >= button53 && msg.y <= button54)
                {
                    lc++;  // ��ť5�ķ�Χ����ʾ�л�������ɫ
                    if (lc > 9)
                        lc = 1;
                    startX = endX = 0;
                }
                else if (msg.x >= button61 && msg.x <= button62 && msg.y >= button63 && msg.y <= button64)
                {
                    fc++;  // ��ť6�ķ�Χ����ʾ�л������ɫ
                    if (fc > 9)
                        fc = 0;
                    startX = endX = 0;
                }
                else
                {
                    isDragging = true;// ��갴���Ҳ��ڰ�ť��Χ�ڣ���ʾ��ʼ�϶�
                    startX = endX = msg.x;
                    startY = endY = msg.y;
                }
            }
            else if (msg.uMsg == WM_LBUTTONUP) {  // �������ͷ�
                isDragging = false;
                if (shapeType == 0 && startX != 0 && endX != 0)  // Բ��
                {
                    Shape* shape = new myCircle(startX, startY, max(abs(endX - startX), abs(endY - startY)), px, colorType(lc), colorType(fc));
                    Shapes.push_back(shape);
                }
                else if (shapeType == 1 && startX != 0 && endX != 0)  // ����
                {
                    Shape* shape = new myRectangle(startX, startY, (endX - startX), (endY - startY), px, colorType(lc), colorType(fc));
                    Shapes.push_back(shape);
                }
                else if (shapeType == 2 && startX != 0 && endX != 0)  // ��Բ
                {
                    Shape* shape = new myEllipse(startX, startY, endX, endY, px, colorType(lc), colorType(fc));
                    Shapes.push_back(shape);
                }
                else if (shapeType == 3 && startX != 0 && endX != 0)  // �߶�
                {
                    Shape* shape = new myLine(startX, startY, endX, endY, px, colorType(lc));
                    Shapes.push_back(shape);
                }
                Refresh(shapeType, lc, fc, px);

            }
            else if (msg.uMsg == WM_MOUSEMOVE) {  // ����ƶ�
                if (isDragging) {
                    endX = msg.x;
                    endY = msg.y;
                    Refresh(shapeType, lc, fc, px);

                    BeginBatchDraw(); //��ʼ������ͼ �������Ƶ�����⣬����������ӳ�
                    if (shapeType == 0)  // Բ��
                    {
                        myCircle tempShape(startX, startY, max(abs(endX - startX), abs(endY - startY)), px, colorType(lc), colorType(fc));
                        tempShape.draw();
                    }
                    else if (shapeType == 1)  // ����
                    {
                        myRectangle tempShape(startX, startY, (endX - startX), (endY - startY), px, colorType(lc), colorType(fc));
                        tempShape.draw();
                    }
                    else if (shapeType == 2)  // ��Բ
                    {
                        myEllipse tempShape(startX, startY, endX, endY, px, colorType(lc), colorType(fc));
                        tempShape.draw();
                    }
                    else if (shapeType == 3)  // �߶�
                    {
                        myLine tempShape(startX, startY, endX, endY, px, colorType(lc));
                        tempShape.draw();
                    }
                    EndBatchDraw(); //������������
                }
            }
        }

        if (_kbhit()) { //���������¼�
            //�˳�����
            char ch = _getch();
            if (ch == 27) {  // ����ESC��
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
            //����
            else if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState('Z') & 0x8000) { // ���Ctrl+Z��ϼ��Ƿ񱻰���
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
    cout << "�����뱣����ļ���:(.txt��β)\n>>>";
    cin >> filename;

    ofstream file(filename, ios::out | ios::binary);  // ʹ�� ofstream �������ļ�����������Զ�����ģʽ��
    for (const auto& shape : Shapes) {
        shape->SaveToFile(file);  // ��̬���� SaveToFile ����
    }
    file.close();
}

void Canvas::Load() {
    std::string filename;
    std::cout << "����Ҫ��ȡ���ļ���:(.txt��β)\n>>>";
    std::cin >> filename;
    
    ifstream file(filename, ios::in | ios::binary);  // ʹ�� ifstream �������ļ������������Զ�����ģʽ��
    if (!file) {
        cout << "�޷����ļ�" << endl;
        return;
    }
    while (true) {
        int type;
        file.read(reinterpret_cast<char*>(&type), sizeof(int));  // ��ȡ��״����
        if (file.eof()) break;  // �����ȡ���ļ���β
        int posX, posY, radius, posX2, posY2, lineWidth;
        COLORREF lineColor, fillColor;
        if (type == 1) {  // Բ��
            file.read(reinterpret_cast<char*>(&posX), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY), sizeof(int));
            file.read(reinterpret_cast<char*>(&radius), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineWidth), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineColor), sizeof(COLORREF));
            file.read(reinterpret_cast<char*>(&fillColor), sizeof(COLORREF));
            Shapes.push_back(new myCircle(posX, posY, radius, lineWidth, lineColor, fillColor));
        }
        else if(type == 2) {  //����
            file.read(reinterpret_cast<char*>(&posX), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY), sizeof(int));
            file.read(reinterpret_cast<char*>(&posX2), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY2), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineWidth), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineColor), sizeof(COLORREF));
            file.read(reinterpret_cast<char*>(&fillColor), sizeof(COLORREF));
            Shapes.push_back(new myRectangle(posX, posY, posX2, posY2, lineWidth, lineColor, fillColor));
        }
        else if (type == 3) {  //��Բ
            file.read(reinterpret_cast<char*>(&posX), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY), sizeof(int));
            file.read(reinterpret_cast<char*>(&posX2), sizeof(int));
            file.read(reinterpret_cast<char*>(&posY2), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineWidth), sizeof(int));
            file.read(reinterpret_cast<char*>(&lineColor), sizeof(COLORREF));
            file.read(reinterpret_cast<char*>(&fillColor), sizeof(COLORREF));
            Shapes.push_back(new myEllipse(posX, posY, posX2, posY2, lineWidth, lineColor, fillColor));
        }
        else if (type == 4) {  //�߶�
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
    BeginBatchDraw(); //��ʼ������ͼ
    for (size_t i = 0; i < Shapes.size(); i++) {
        Shapes[i]->draw();
    }
    EndBatchDraw(); //������������
    IMAGE img;
    getimage(&img, 0, 0, 640, 480);

    saveimage(_T("output.jpg"), &img);
    closegraph();
    cout << "�ѱ���Ϊoutput.jpg\n��Enter����...";
    getchar();
    getchar();
}
