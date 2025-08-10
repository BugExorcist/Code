#include "UserMenu.h"
Canvas canvas;

void clearWindow() {
	//system("cls");  // ��տ���̨���� ����windoseϵͳ ���ȶ� ���ܱ���
	// ��տ���̨����
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
	cout << "*          ��ӭʹ�ü��׻�ͼϵͳ          *" << endl;
	cout << "*                                        *" << endl;
	cout << "*   1.������ͼ��      2.���̻���ͼ��   *" << endl;
	cout << "*   3.�����ɫ          4.չʾ��ͼ       *" << endl;
	cout << "*   5.���ȫ��ͼ�β���  6.ɾ��ͼ��       *" << endl;
	cout << "*   7.����              8.��ȡ           *" << endl;
	cout << "*   9.���Ϊjpg         0.�˳�ϵͳ       *" << endl;
	cout << "*        *�������Ӧ���ֽ��в���*        *" << endl;
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
		cout << "�����������������" ;
		Choice();
	}
}

COLORREF colorType() {
	cout << "1.�� 2.�� 3.�� 4.�� 5.��" << endl;
	cout << "6.�� 7.�� 8.�� 9.��" << endl;
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
		cout << "�������";
		return colorType();
	}
}

void drawShapes() {
	cout << "1.Բ��  2.����  3.��Բ��  4.�߶� 5.����Ԥ��ͼ�� 6.����" << endl;
	cout << "������Χ 640x480" << endl;
	cout << ">>>";
	char type;
	cin >> type;
	int x = 0, y = 0, rx = 0, ry = 0, r = 0, lw = 0;
	COLORREF lc = WHITE, fc = BLACK;
	switch (type)
	{
	case '1':
		cout << "������Բ�ĵ�����X������Y���뾶���ߴ�" << endl;
		cout << ">>>";
		cin >> x >> y >> r >> lw ;
		cout << "��ѡ��������ɫ" << endl;
		lc = colorType();
		canvas.addCircle(x, y, r, lw, lc, fc);
		break;
	case '2':
		cout << "��������ε����Ͻ�����X������Y����ȡ����ȡ��ߴ�" << endl;
		cout << ">>>";
		cin >> x >> y >> rx >> ry >> lw;
		cout << "��ѡ��������ɫ" << endl;
		lc = colorType();
		canvas.addRectangle(x, y, rx, ry, lw, lc, fc);
		break;
	case '3':
		cout << "��������Բ���о��ε����Ͻ�����X��Y�����½�����X��Y���ߴ�" << endl;
		cout << ">>>";
		cin >> x >> y >> rx >> ry >> lw;
		cout << "��ѡ��������ɫ" << endl;
		lc = colorType();
		canvas.addEllipse(x, y, rx, ry, lw, lc, fc);
		break;
	case '4':
		cout << "�������߶ε���ʼ����X��Y�ͽ�������X��Y���ߴ�" << endl;
		cout << ">>>";
		cin >> x >> y >> rx >> ry >> lw;
		cout << "��ѡ��������ɫ" << endl;
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
		cout << "�������";
		getchar();
		drawShapes();
	}
	Menu();
}

void deleteShapes() {
	canvas.displayShapes();
	cout << "��ѡ��Ҫɾ����ͼ����ţ�����0ɾ��ȫ��ͼ�Σ�" << endl;
	cout << ">>>";
	int num;
	cin >> num;
	if (num == 0) {
			cout << "ȷ��ɾ��ȫ��ͼ����" << endl;
			cout << "(Y/N)>>>";
			char x;
			cin >> x;
			if (x == 'Y') {
				canvas.deleteShape(num);
				cout << "��ȫ��ɾ����" << endl;
			}
	}
	else if (num > 0 && num <= canvas.Size()) {
		canvas.deleteShape(num);
	}
	else {
		cout << "û�д�ͼ�Σ�" << endl;
	}
	Menu();
}

void fillColor() {
	canvas.displayShapes();
	cout << "��ѡ��Ҫ����ͼ�����" << endl;
	cout << ">>>";
	int num;
	cin >> num;
	if (num > 0 && num <= canvas.Size()) {
		cout << "��������ɫ" << endl;
		cout << ">>>";
		COLORREF fc = BLACK;
		fc = colorType();
		canvas.fillColor(num, fc);
	}
	else
		cout << "û�д�ͼ�Σ�" << endl;
	Menu();
}

void showShapes() {
	canvas.drawShapes();
	Menu();
}

void displayDatas() {
	clearWindow();
	canvas.displayShapes();
	cout << "��Enter����..." << endl;
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
	cout << "����˵����" << endl;
	cout << "+/-������/��С�������� Ctrl+Z������ END���˳���ͼ" << endl;
	cout << "��Enter����..." << endl;
	getchar();
	getchar();
	canvas.mouseOperation();
	Menu();
}

void outputJPG() {
	canvas.outputjpg();
	Menu();
}