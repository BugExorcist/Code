#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
using namespace std;

int disk_block[10000000], disk_empty = 1000000;
typedef struct UFD { //存储文件信息
	char name[10];//文件名
	int attribute;//文件属性
	string s;//文件内容
	int length;//文件长度
	int a[100];//为文件本身分配100个空间
	struct UFD* next;
} UFD;
typedef struct DIR { //存储目录信息
	DIR* above;//上一结点
	char name[10];
	int length;
	DIR* next;//下一结点
	UFD* File_head;//此目录下的文件指针
	DIR* Dir_head;//此目录下目录链表指针
} DIR;
class Cuse { //定义管理用户目录的类
	DIR* now;//当前目录
	UFD* Fhead;//文件的头结点
	DIR* Dhead;//根目录的目录链头结点
	int length;//用户空间大小
	int status;//是否获得空间
public:
	void set_status(int);
	int dele_user();
	int dis_file();//显示文件所占外存块号d 
	int dis_dir(DIR* d);//当前路径
	DIR* get_now();
	int dele_file(UFD* f);//删除文件
	int dele_dir(DIR*);//删除目录
	Cuse();//构造
	~Cuse();//析构
	int goback();//返回上级目录
	int dis_now();//查看当前目录
	int new_file();
	int new_dir();
	int open_dir();
	int first_dele_file();//删除文件的前部分工作
	int first_dele_dir();//删除目录的前部分工作
};
Cuse::Cuse() { //构造函数，初始化成员
	status = 0;//用户权利，即是否被创建标记
	length = 0;//空间
	now = 0;//当前目录
	Fhead = 0;//文件
	Dhead = 0;//目录
}
Cuse::~Cuse() { //清除程序占用的内存
	disk_empty += length;
	length = 0;
	UFD* f = Fhead;
	DIR* d = Dhead;
	while (f != 0) { //文件
		if (f->next == 0) {
			this->dele_file(f);
			f = 0;
			break;
		}
		while (f->next->next != 0)
			f = f->next;
		this->dele_file(f->next);
		f->next = 0;
		f = Fhead;
	}
	while (d != 0) {	//目录
		if (d->next == 0) {
			this->dele_dir(d);
			d = 0;
			break;
		}
		while (d->next->next != 0)
			d = d->next;
		this->dele_dir(d->next);
		d->next = 0;
		d = Dhead;
	}
}
int Cuse::new_file() {	//建立新文件
	int i = 0, j = 0;
	UFD* f, * p = 0;
	DIR* D;

	p = new UFD;
	cout << "请输入建立的文件名：";
	cin >> p->name;
	cout << endl;
	if (now == 0)
		f = Fhead;
	else
		f = now->File_head;
	while (f != 0) {
		if (!strcmp(p->name, f->name)) {
			cout << "此文件已存在！" << endl;
			return 0;
		}
		f = f->next;
	}
	cout << "当前空间大小为：" << disk_empty << endl;
	cout << "\n" << "设定文件属性(0：只读，1：读写)：";
	cin >> p->attribute;
	cout << "\n" << "请输入文件内容：";
	cin >> p->s;
	p->length = p->s.size();
	cout << "\n创建文件成功! 当前文件大小为： " << p->length << endl;

	cout << endl;
	if (p->length > disk_empty) {
		cout << "文件太大，空间不足，当前空间为：" << disk_empty << endl;
		delete p;
		return 0;
	}
	disk_empty = disk_empty - p->length;
	for (i = 0; i < p->length && i < 10; i++)
		for (j; j < 10000; j++)
			if (disk_block[j] == 0) {
				p->a[i] = j;
				disk_block[j] = 1;
				j++;
				break;
			}
	if (now == 0) {
		p->next = Fhead;
		Fhead = p;
	}
	else {
		p->next = now->File_head;
		now->File_head = p;
	}
	length += p->length;
	if (now != 0) {
		now->length += p->length;
		D = now->above;
		while (D != 0) {
			D->length += p->length;
			D = D->above;
		}
	}

	return 0;
}

int Cuse::first_dele_file() {
	char temp[10], a[5];
	cout << "请输入你要删除的文件名：";
	cin >> temp;
	UFD* f = Fhead;
	UFD* above = 0;
	if (now != 0)
		f = now->File_head;
	while (f != 0) {
		if (!strcmp(f->name, temp))
			break;
		above = f;
		f = f->next;
	}
	if (f == 0) {
		cout << "\n此文件不存在" << endl;
		return 0;
	}
	cout << "\n确定删除" << f->name << "文件吗（y/n）： ";
	cin >> a;
	if (a[0] != 'y') {
		cout << "\n已取消删除文件!" << endl;
		return 0;
	}
	disk_empty += f->length;
	if (now == 0) {
		if (f == Fhead)
			Fhead = Fhead->next;
		else
			above->next = f->next;
	}
	else {
		DIR* d = now;
		while (d != 0) {
			d->length -= f->length;
			d = d->above;
		}
		if (f == now->File_head)
			now->File_head = now->File_head->next;
		else
			above->next = f->next;
	}
	length -= f->length;
	this->dele_file(f);
	cout << "\n文件删除成功！" << endl;
	return 1;
}

int Cuse::dele_file(UFD* f) {
	int i = 0, m;
	for (i = 0; i < 100 && i < f->length; i++) {
		m = f->a[i];
		disk_block[m] = 0;
	}
	f = 0;
	return 1;
}



int Cuse::new_dir() {
	DIR* p, * h;
	cout << "请输入新目录的名字：";
	p = new DIR;
	cin >> p->name;
	p->Dir_head = 0;
	p->length = 0;
	p->File_head = 0;
	if (now == 0)
		h = Dhead;
	else
		h = now->Dir_head;
	while (h != 0) {
		if (!strcmp(h->name, p->name)) {
			cout << "\n此目录已存在！" << endl;
			return 0;
		}
		h = h->next;
	}
	if (now == 0) {
		p->above = 0;
		p->next = Dhead;
		Dhead = p;
	}
	else {
		p->above = now;
		p->next = now->Dir_head;
		now->Dir_head = p;
	}
	cout << "\n目录创建成功!" << endl;
	return 1;
}




int Cuse::goback() {
	if (now == 0) {
		cout << "\n已是主目录，不能向上！" << endl;
		return 0;
	}
	now = now->above;
	return 1;
}
int Cuse::open_dir() {
	char name[10];
	DIR* p;
	if (now == 0)
		p = Dhead;
	else
		p = now->Dir_head;
	cout << "请输入你要打开的目录名：";
	cin >> name;
	while (p != 0) {
		if (strcmp(p->name, name) == 0) {
			now = p;
			return 1;
		}
		p = p->next;
	}
	cout << "\n当前没此目录!" << endl;
	return 0;
}


int Cuse::first_dele_dir() {
	char n[10];
	DIR* p, * above = 0;
	p = Dhead;
	if (now != 0)
		p = now->Dir_head;
	cout << "要删除的目录名：";
	cin >> n;
	while (p != 0) {
		if (!strcmp(p->name, n))
			break;
		above = p;
		p = p->next;
	}
	if (p == 0) {
		cout << "\\没有这个目录！" << endl;
		return 0;
	}
	cout << "\n确定删除当前目录所有信息吗(y/n): ";
	string c;
	cin >> c;
	if (c != "y")
		return 0;
	disk_empty += p->length;
	if (now == 0) {
		if (p == Dhead)
			Dhead = Dhead->next;
		else
			above->next = p->next;
	}
	else {
		if (p == now->Dir_head)
			now->Dir_head = now->Dir_head->next;
		else
			above->next = p->next;
		above = now;
		while (above != 0) {
			above->length -= p->length;
			above = above->above;
		}
	}
	length -= p->length;
	this->dele_dir(p);
	p = 0;
	cout << "\n删除成功！" << endl;
	return 1;
}
int Cuse::dele_dir(DIR* p) {
	int flag = 0;
	DIR* d = p->Dir_head;
	UFD* f = p->File_head;
	if (f != 0) {
		while (p->File_head->next != 0) {
			f = p->File_head;
			while (f->next->next != 0)
				f = f->next;
			this->dele_file(f->next);
			f->next = 0;
		}
		if (p->File_head->next == 0) {
			this->dele_file(p->File_head);
			p->File_head = 0;
		}
	}
	if (d != 0) {
		while (p->Dir_head->next != 0) {
			d = p->Dir_head;
			while (d->next->next != 0)
				d = d->next;
			this->dele_dir(d->next);
			d->next = 0;
		}
		if (p->Dir_head->next == 0) {
			this->dele_dir(p->Dir_head);
			p->Dir_head = 0;
		}
	}
	delete p;
	p = 0;
	return 1;
}
int Cuse::dis_now() {
	DIR* d = Dhead;//目录的头节点
	UFD* f = Fhead;//文件的头节点
	if (now != 0) {//目录下面不为空
		d = now->Dir_head;//让目录的头节点等于此目录下根目录
		f = now->File_head;//让文件的头节点指向该目录头文件的
	}
	if (d == 0 && f == 0) {
		cout << "\n当前目录为空!" << endl;
		return 0;
	}
	cout << "当前目录大小：";
	if (now == 0) cout << length;
	else cout << now->length;
	cout << endl;
	if (d == 0) cout << "当前目录下没有目录" << endl;
	else {
		cout << "当前目录下包含如下目录：" << endl;
		cout << setw(14) << "目录名称" << setw(14) << "目录大小" << endl;
		while (d != 0) {
			cout << setw(14) << d->name << setw(14) << d->length << endl;
			d = d->next;
		}
	}
	if (f == 0) cout << "当前目录下没有文件" << endl;
	else {
		cout << "当前目录下包含如下文件:" << endl;
		cout << setw(14) << "文件名称" << setw(14) << "文件大小" << setw(14) << "文件属性" << endl;
		while (f != 0) {
			cout << setw(14) << f->name << setw(14) << f->length << setw(14) << f->attribute << endl;
			f = f->next;
		}
	}
	return 1;
}
DIR* Cuse::get_now() {
	return now;
}
int Cuse::dis_dir(DIR* d) {
	if (d == 0) return 0;
	if (d->above != 0) this->dis_dir(d->above);
	cout << "	" << d->name << endl << endl;
	return 0;
}
int Cuse::dis_file() {
	int i;
	char n[10];
	UFD* f = Fhead;
	if (now != 0)
		f = now->File_head;
	cout << "请输入要查看的文件名：";
	cin >> n;
	while (f != 0) {
		if (!strcmp(n, f->name))
			break;
		f = f->next;
	}
	if (f == 0) {
		cout << "\n当前目录下没此文件!" << endl;
		return 0;
	}
	if (f->attribute == 0) {
		cout << "\n此为只读文件..." << endl;
		cout << "内容为：" << f->s << endl;
		cout << "\n该文件磁盘空间使用情况：";
		for (int i = 0; i < f->length && i < 10; i++) {
			cout << setw(6) << f->a[i];
			if ((i + 1) % 10 == 0) cout << endl;
		}
	}
	else {
		cout << "\n内容为：" << f->s;
		cout << "\n此为读写文件，是否修改内容(y/n): ";
		string k;
		cin >> k;
		if (k == "y") {
			cout << "\n请输入修改后的内容： ";
			cin >> f->s;
			cout << "\n修改成功！" << endl;
		}
		else {
			cout << "\n该文件使用磁盘空间明细：";
			for (int i = 0; i < f->length && i < 10; i++) {
				cout << setw(6) << f->a[i];
				if ((i + 1) % 10 == 0) cout << endl;
			}
		}
	}
	cout << endl;
	return 1;
}
int main() {
	char c;
	Cuse D;//创建用户管理文件类 
	int i = 1, flag = 1;
	while (flag) {
		while (flag) {
			cout << endl;
			cout << "[1]创建文件（包含写文件的操作）" << "   [2]删除文件" << endl << endl;
			cout << "[3]查看文件（即读文件）" << "           [4]创建目录" << endl << endl;
			cout << "[5]删除目录" << "                       [6]打开目录" << endl << endl;
			cout << "[7]查看当前目录" << "                   [8]返回上层目录" << endl << endl;
			cout << "[0]退出" << endl << endl;
			cout << "目录为:Root" << endl << endl;
			D.dis_dir(D.get_now());
			cout << "\n请输入选择：";
			string op;
			cin >> op;
			cout << endl;
			if (op == "1") D.new_file();
			else if (op == "2") D.first_dele_file();
			else if (op == "3") D.dis_file();
			else if (op == "4") D.new_dir();
			else if (op == "5") D.first_dele_dir();
			else if (op == "6") D.open_dir();
			else if (op == "7") D.dis_now();
			else if (op == "8") D.goback();
			else if (op == "0") {
				flag = 0;
				system("cls");
			}
			else cout << "操作无效！" << endl;
		}
		flag = 1;
		break;
	}
}