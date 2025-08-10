#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
using namespace std;

int disk_block[10000000], disk_empty = 1000000;
typedef struct UFD { //�洢�ļ���Ϣ
	char name[10];//�ļ���
	int attribute;//�ļ�����
	string s;//�ļ�����
	int length;//�ļ�����
	int a[100];//Ϊ�ļ��������100���ռ�
	struct UFD* next;
} UFD;
typedef struct DIR { //�洢Ŀ¼��Ϣ
	DIR* above;//��һ���
	char name[10];
	int length;
	DIR* next;//��һ���
	UFD* File_head;//��Ŀ¼�µ��ļ�ָ��
	DIR* Dir_head;//��Ŀ¼��Ŀ¼����ָ��
} DIR;
class Cuse { //��������û�Ŀ¼����
	DIR* now;//��ǰĿ¼
	UFD* Fhead;//�ļ���ͷ���
	DIR* Dhead;//��Ŀ¼��Ŀ¼��ͷ���
	int length;//�û��ռ��С
	int status;//�Ƿ��ÿռ�
public:
	void set_status(int);
	int dele_user();
	int dis_file();//��ʾ�ļ���ռ�����d 
	int dis_dir(DIR* d);//��ǰ·��
	DIR* get_now();
	int dele_file(UFD* f);//ɾ���ļ�
	int dele_dir(DIR*);//ɾ��Ŀ¼
	Cuse();//����
	~Cuse();//����
	int goback();//�����ϼ�Ŀ¼
	int dis_now();//�鿴��ǰĿ¼
	int new_file();
	int new_dir();
	int open_dir();
	int first_dele_file();//ɾ���ļ���ǰ���ֹ���
	int first_dele_dir();//ɾ��Ŀ¼��ǰ���ֹ���
};
Cuse::Cuse() { //���캯������ʼ����Ա
	status = 0;//�û�Ȩ�������Ƿ񱻴������
	length = 0;//�ռ�
	now = 0;//��ǰĿ¼
	Fhead = 0;//�ļ�
	Dhead = 0;//Ŀ¼
}
Cuse::~Cuse() { //�������ռ�õ��ڴ�
	disk_empty += length;
	length = 0;
	UFD* f = Fhead;
	DIR* d = Dhead;
	while (f != 0) { //�ļ�
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
	while (d != 0) {	//Ŀ¼
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
int Cuse::new_file() {	//�������ļ�
	int i = 0, j = 0;
	UFD* f, * p = 0;
	DIR* D;

	p = new UFD;
	cout << "�����뽨�����ļ�����";
	cin >> p->name;
	cout << endl;
	if (now == 0)
		f = Fhead;
	else
		f = now->File_head;
	while (f != 0) {
		if (!strcmp(p->name, f->name)) {
			cout << "���ļ��Ѵ��ڣ�" << endl;
			return 0;
		}
		f = f->next;
	}
	cout << "��ǰ�ռ��СΪ��" << disk_empty << endl;
	cout << "\n" << "�趨�ļ�����(0��ֻ����1����д)��";
	cin >> p->attribute;
	cout << "\n" << "�������ļ����ݣ�";
	cin >> p->s;
	p->length = p->s.size();
	cout << "\n�����ļ��ɹ�! ��ǰ�ļ���СΪ�� " << p->length << endl;

	cout << endl;
	if (p->length > disk_empty) {
		cout << "�ļ�̫�󣬿ռ䲻�㣬��ǰ�ռ�Ϊ��" << disk_empty << endl;
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
	cout << "��������Ҫɾ�����ļ�����";
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
		cout << "\n���ļ�������" << endl;
		return 0;
	}
	cout << "\nȷ��ɾ��" << f->name << "�ļ���y/n���� ";
	cin >> a;
	if (a[0] != 'y') {
		cout << "\n��ȡ��ɾ���ļ�!" << endl;
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
	cout << "\n�ļ�ɾ���ɹ���" << endl;
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
	cout << "��������Ŀ¼�����֣�";
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
			cout << "\n��Ŀ¼�Ѵ��ڣ�" << endl;
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
	cout << "\nĿ¼�����ɹ�!" << endl;
	return 1;
}




int Cuse::goback() {
	if (now == 0) {
		cout << "\n������Ŀ¼���������ϣ�" << endl;
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
	cout << "��������Ҫ�򿪵�Ŀ¼����";
	cin >> name;
	while (p != 0) {
		if (strcmp(p->name, name) == 0) {
			now = p;
			return 1;
		}
		p = p->next;
	}
	cout << "\n��ǰû��Ŀ¼!" << endl;
	return 0;
}


int Cuse::first_dele_dir() {
	char n[10];
	DIR* p, * above = 0;
	p = Dhead;
	if (now != 0)
		p = now->Dir_head;
	cout << "Ҫɾ����Ŀ¼����";
	cin >> n;
	while (p != 0) {
		if (!strcmp(p->name, n))
			break;
		above = p;
		p = p->next;
	}
	if (p == 0) {
		cout << "\\û�����Ŀ¼��" << endl;
		return 0;
	}
	cout << "\nȷ��ɾ����ǰĿ¼������Ϣ��(y/n): ";
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
	cout << "\nɾ���ɹ���" << endl;
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
	DIR* d = Dhead;//Ŀ¼��ͷ�ڵ�
	UFD* f = Fhead;//�ļ���ͷ�ڵ�
	if (now != 0) {//Ŀ¼���治Ϊ��
		d = now->Dir_head;//��Ŀ¼��ͷ�ڵ���ڴ�Ŀ¼�¸�Ŀ¼
		f = now->File_head;//���ļ���ͷ�ڵ�ָ���Ŀ¼ͷ�ļ���
	}
	if (d == 0 && f == 0) {
		cout << "\n��ǰĿ¼Ϊ��!" << endl;
		return 0;
	}
	cout << "��ǰĿ¼��С��";
	if (now == 0) cout << length;
	else cout << now->length;
	cout << endl;
	if (d == 0) cout << "��ǰĿ¼��û��Ŀ¼" << endl;
	else {
		cout << "��ǰĿ¼�°�������Ŀ¼��" << endl;
		cout << setw(14) << "Ŀ¼����" << setw(14) << "Ŀ¼��С" << endl;
		while (d != 0) {
			cout << setw(14) << d->name << setw(14) << d->length << endl;
			d = d->next;
		}
	}
	if (f == 0) cout << "��ǰĿ¼��û���ļ�" << endl;
	else {
		cout << "��ǰĿ¼�°��������ļ�:" << endl;
		cout << setw(14) << "�ļ�����" << setw(14) << "�ļ���С" << setw(14) << "�ļ�����" << endl;
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
	cout << "������Ҫ�鿴���ļ�����";
	cin >> n;
	while (f != 0) {
		if (!strcmp(n, f->name))
			break;
		f = f->next;
	}
	if (f == 0) {
		cout << "\n��ǰĿ¼��û���ļ�!" << endl;
		return 0;
	}
	if (f->attribute == 0) {
		cout << "\n��Ϊֻ���ļ�..." << endl;
		cout << "����Ϊ��" << f->s << endl;
		cout << "\n���ļ����̿ռ�ʹ�������";
		for (int i = 0; i < f->length && i < 10; i++) {
			cout << setw(6) << f->a[i];
			if ((i + 1) % 10 == 0) cout << endl;
		}
	}
	else {
		cout << "\n����Ϊ��" << f->s;
		cout << "\n��Ϊ��д�ļ����Ƿ��޸�����(y/n): ";
		string k;
		cin >> k;
		if (k == "y") {
			cout << "\n�������޸ĺ�����ݣ� ";
			cin >> f->s;
			cout << "\n�޸ĳɹ���" << endl;
		}
		else {
			cout << "\n���ļ�ʹ�ô��̿ռ���ϸ��";
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
	Cuse D;//�����û������ļ��� 
	int i = 1, flag = 1;
	while (flag) {
		while (flag) {
			cout << endl;
			cout << "[1]�����ļ�������д�ļ��Ĳ�����" << "   [2]ɾ���ļ�" << endl << endl;
			cout << "[3]�鿴�ļ��������ļ���" << "           [4]����Ŀ¼" << endl << endl;
			cout << "[5]ɾ��Ŀ¼" << "                       [6]��Ŀ¼" << endl << endl;
			cout << "[7]�鿴��ǰĿ¼" << "                   [8]�����ϲ�Ŀ¼" << endl << endl;
			cout << "[0]�˳�" << endl << endl;
			cout << "Ŀ¼Ϊ:Root" << endl << endl;
			D.dis_dir(D.get_now());
			cout << "\n������ѡ��";
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
			else cout << "������Ч��" << endl;
		}
		flag = 1;
		break;
	}
}