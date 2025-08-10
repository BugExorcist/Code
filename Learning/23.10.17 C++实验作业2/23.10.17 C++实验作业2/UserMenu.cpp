#include "UserMenu.h"
Canvas canvas;

void clearWindow() {
	//system("cls");  // 清空控制台内容 依赖windose系统 不稳定 可能崩溃
	// 清空控制台内容
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdout, &csbi);
	FillConsoleOutputCharacter(hStdout, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
	SetConsoleCursorPosition(hStdout, coord);
}

void Menu(){
	clearWindow();
	cout << "******************************************" << endl;
	cout << "*          欢迎使用简易绘图系统          *" << endl;
	cout << "*                                        *" << endl;
	cout << "*   1.鼠标绘制图形      2.键盘绘制图形   *" << endl;
	cout << "*   3.填充颜色          4.展示绘图       *" << endl;
	cout << "*   5.输出全部图形参数  6.删除图形       *" << endl;
	cout << "*   7.保存              8.读取           *" << endl;
	cout << "*   9.输出为jpg         0.退出系统       *" << endl;
	cout << "*        *请输入对应数字进行操作*        *" << endl;
	cout << "******************************************" << endl;
	Choice();
}

void Choice() {
	cout << ">>>";
	char x;
	cin >> x;
	switch (x)
	{
	case '1':
		mouseOperation();
		break;
	case '2':
		drawShapes();
		break;
	case '3':
		fillColor();
		break;
	case '4':
		showShapes();
		break;
	case '5':
		displayDatas();
		break;
	case '6':
		deleteShapes();
		break;
	case '7':
		Save();
		break;
	case '8':
		Load();
		break;
	case '9':
		outputJPG();
		break;
	case '0':
		Exit();
		break;
	default:
		cout << "输入错误！请重新输入" ;
		Choice();
	}
}

COLORREF colorType() {
	cout << "1.白 2.蓝 3.绿 4.青 5.红" << endl;
	cout << "6.紫 7.棕 8.黄 9.灰" << endl;
	cout << ">>>";
	char x;
	cin >> x;
	switch (x)
	{
	case '1':
		return WHITE;
		break;
	case '2':
		return BLUE;
		break; 
	case '3':
		return GREEN;
		break;
	case '4':
		return CYAN;
		break;
	case '5':
		return RED;
		break;
	case '6':
		return MAGENTA;
		break;
	case '7':
		return BROWN;
		break;
	case '8':
		return YELLOW;
		break;
	case '9':
		return DARKGRAY;
		break;
	default:
		cout << "输入错误！";
		return colorType();
	}
}

void drawShapes() {
	cout << "1.圆形  2.矩形  3.椭圆形  4.线段 5.加入预设图形 6.返回" << endl;
	cout << "画布范围 640x480" << endl;
	cout << ">>>";
	char type;
	cin >> type;
	int x = 0, y = 0, rx = 0, ry = 0, r = 0, lw = 0;
	COLORREF lc = WHITE, fc = BLACK;
	switch (type)
	{
	case '1':
		cout << "请输入圆心的坐标X、坐标Y、半径、线粗" << endl;
		cout << ">>>";
		cin >> x >> y >> r >> lw ;
		cout << "请选择线条颜色" << endl;
		lc = colorType();
		canvas.addCircle(x, y, r, lw, lc, fc);
		break;
	case '2':
		cout << "请输入矩形的左上角坐标X、坐标Y、宽度、长度、线粗" << endl;
		cout << ">>>";
		cin >> x >> y >> rx >> ry >> lw;
		cout << "请选择线条颜色" << endl;
		lc = colorType();
		canvas.addRectangle(x, y, rx, ry, lw, lc, fc);
		break;
	case '3':
		cout << "请输入椭圆外切矩形的左上角坐标X、Y、右下角坐标X、Y、线粗" << endl;
		cout << ">>>";
		cin >> x >> y >> rx >> ry >> lw;
		cout << "请选择线条颜色" << endl;
		lc = colorType();
		canvas.addEllipse(x, y, rx, ry, lw, lc, fc);
		break;
	case '4':
		cout << "请输入线段的起始坐标X、Y和结束坐标X、Y、线粗" << endl;
		cout << ">>>";
		cin >> x >> y >> rx >> ry >> lw;
		cout << "请选择线条颜色" << endl;
		lc = colorType();
		canvas.addLine(x, y, rx, ry, lw, lc);
		break;
	case '5':
		canvas.addCircle(100, 100, 20, 2, BLUE, CYAN);
		canvas.addEllipse(130, 60, 300, 150, 3, YELLOW, DARKGRAY);
		canvas.addRectangle(500, 20, 50, 100, 4, WHITE, BROWN);
		canvas.addLine(200, 200, 250, 300, 2, BROWN);
		canvas.addLine(500, 400, 50, 400, 2, CYAN);
		break;
	case '6':
		break;
	default:
		cout << "输入错误！";
		getchar();
		drawShapes();
	}
	Menu();
}

void deleteShapes() {
	canvas.displayShapes();
	cout << "请选择要删除的图形序号（输入0删除全部图形）" << endl;
	cout << ">>>";
	int num;
	cin >> num;
	if (num == 0) {
			cout << "确认删除全部图形吗？" << endl;
			cout << "(Y/N)>>>";
			char x;
			cin >> x;
			if (x == 'Y') {
				canvas.deleteShape(num);
				cout << "已全部删除！" << endl;
			}
	}
	else if (num > 0 && num <= canvas.Size()) {
		canvas.deleteShape(num);
	}
	else {
		cout << "没有此图形！" << endl;
	}
	Menu();
}

void fillColor() {
	canvas.displayShapes();
	cout << "请选择要填充的图形序号" << endl;
	cout << ">>>";
	int num;
	cin >> num;
	if (num > 0 && num <= canvas.Size()) {
		cout << "请输入颜色" << endl;
		cout << ">>>";
		COLORREF fc = BLACK;
		fc = colorType();
		canvas.fillColor(num, fc);
	}
	else
		cout << "没有此图形！" << endl;
	Menu();
}

void showShapes() {
	canvas.drawShapes();
	Menu();
}

void displayDatas() {
	clearWindow();
	canvas.displayShapes();
	cout << "按Enter继续..." << endl;
	getchar();
	getchar();
	Menu();
}

void Exit() {
	canvas.~Canvas();
}

void Save() {
	canvas.Save();
	Menu();
}

void Load() {
	canvas.Load();
	Menu();
}

void mouseOperation() {
	cout << "操作说明：" << endl;
	cout << "+/-：增加/减小画线像素 Ctrl+Z：撤回 END：退出画图" << endl;
	cout << "按Enter继续..." << endl;
	getchar();
	getchar();
	canvas.mouseOperation();
	Menu();
}

void outputJPG() {
	canvas.outputjpg();
	Menu();
}