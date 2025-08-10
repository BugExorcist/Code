#include <iostream>
using namespace std;

#define FREE 0  // ��ʾ����
#define  BUSY 1  // ��ʾ�ѷ���
#define  MAX_length 64  //�ռ��С


typedef struct free_area //���ȶ���������ֱ�ṹ
{
	int flag;//״̬
	int size;//��С
	int number;//���
	int begin_address;
}Elemtype;

typedef struct Free_Node
{
	Elemtype date;
	struct Free_Node* prior;
	struct Free_Node* next;
}Free_Node, * pNod;

pNod headNode;
pNod initNode;
pNod flagNode;//���ڼ�¼ѭ���״���Ӧ�㷨�Ŀ�ʼ�ڵ�
int allocation();//��ҵ����
void free(int number);//��ҵ����
bool ff(int number, int size);//�״���Ӧ�㷨
bool nf(int number, int size);//ѭ���״���Ӧ�㷨
void type_change();//�����㷨����
int algorithm_type = 1; //1->�״���Ӧ�㷨 2->ѭ���״���Ӧ�㷨
void show();//�鿴����
void init();//��ʼ��

void init()
{
	// ��ʼ������������
	headNode = new Free_Node;
	initNode = new Free_Node;
	flagNode = new Free_Node;
	// ��ʼ������ͷ���ͳ�ʼ���
	headNode->prior = NULL;
	headNode->next = initNode;
	initNode->prior = headNode;
	initNode->next = NULL;
	initNode->date.begin_address = 0;
	initNode->date.flag = FREE;
	initNode->date.number = 0;
	initNode->date.size = MAX_length;
	flagNode = headNode;
}

//ʵ����ҵ����
int allocation()
{
	int number, size1;
	cout << "��������ҵ�ţ�";
	cin >> number;
	cout << "������������ҵ��С��";
	cin >> size1;

	if (algorithm_type == 1)
	{
		if (ff(number, size1))
		{
			cout << "����ɹ���" << endl;
		}
		else cout << "����ʧ�ܣ�" << endl;
	}
	else if (algorithm_type == 2)
	{
		if (nf(number, size1))
		{
			cout << "����ɹ���" << endl;
		}
		else cout << "����ʧ�ܣ�" << endl;
	}
	getchar();
	getchar();
	return 1;
}

void type_change()
{
	int type;
	cout << "��ѡ����ĵ��㷨 1 - �״���Ӧ�㷨��2 - ѭ���״���Ӧ�㷨" << endl;
	cin >> type;
	if (type >= 1 && type <= 2)
	{
		algorithm_type = type;
	}
	else
	{
		cout << "��Ч������" << endl;
		type_change();
	}
}

bool ff(int number, int size)//�״���Ӧ�㷨
{
	pNod temp = new Free_Node;
	Free_Node* p = headNode->next;  //���׽ڵ㿪ʼ
	temp->date.number = number;
	temp->date.size = size;
	temp->date.flag = BUSY;
	while (p)
	{
		if (p->date.flag == FREE && p->date.size == size)//�����С�պ�����
		{
			p->date.flag = BUSY;
			p->date.number = number;
			return true;
		}
		if (p->date.flag == FREE && p->date.size > size)//˵�����������Ŀ�������
		{
			temp->next = p;
			temp->prior = p->prior;
			temp->date.begin_address = p->date.begin_address;
			p->prior->next = temp;
			p->prior = temp;
			p->date.begin_address = temp->date.begin_address + temp->date.size;//���з�����ʼ��ַ+�˴η���Ŀռ�
			p->date.size -= size;      //���������ҵ
			return true;
		}
		p = p->next;
	}
	return false;
}

bool nf(int number, int size) 
{
	pNod temp = new Free_Node;
	Free_Node* p = flagNode->next;  //�ӱ�ǽڵ㿪ʼ
	temp->date.number = number;
	temp->date.size = size;
	temp->date.flag = BUSY;
	while (p)
	{
		if (p->date.flag == FREE && p->date.size == size)//�����С�պ�����
		{
			p->date.flag = BUSY;
			p->date.number = number;
			flagNode = p->prior;
			return true;
		}
		if (p->date.flag == FREE && p->date.size > size)//˵�����������Ŀ�������
		{
			temp->next = p;
			temp->prior = p->prior;
			temp->date.begin_address = p->date.begin_address;
			p->prior->next = temp;
			p->prior = temp;
			p->date.begin_address = temp->date.begin_address + temp->date.size;//���з�����ʼ��ַ+�˴η���Ŀռ�
			p->date.size -= size;      //���������ҵ
			flagNode = p->prior;
			return true;
		}
		p = p->next;
	}
	p = headNode->next;
	while (p != flagNode) 
	{
		if (p->date.flag == FREE && p->date.size == size)
		{
			p->date.flag = BUSY;
			p->date.number = number;
			flagNode = p->prior;
			return true;
		}
		if (p->date.flag == FREE && p->date.size > size)
		{
			temp->next = p;
			temp->prior = p->prior;
			temp->date.begin_address = p->date.begin_address;
			p->prior->next = temp;
			p->prior = temp;
			p->date.begin_address = temp->date.begin_address + temp->date.size;
			p->date.size -= size;
			flagNode = p->prior;
			return true;
		}
		p = p->next;
	}
	return false;
}

void free(int number)//�������
{
	Free_Node* p = headNode->next;
	while (p)
	{
		if (p->date.number == number)//�ҵ�Ҫ���յ�number����
		{
			p->date.flag = FREE;
			p->date.number = FREE;
			//�ж�P��ǰ�������ϵ

			//1�����շ���r����һ�����з�������ʱӦ�úϲ�Ϊһ�������Ŀ���������ʼַΪr�����ڵķ������׵�ַ������СΪ���ߴ�С֮��
			if (p->prior->date.flag == FREE && p->next->date.flag != FREE)
			{
				p->prior->date.size += p->date.size;
				p->prior->next = p->next;  //��Ҫ���շ�����ǰ������������������
				p->next->prior = p->prior;
			}
			//2�����շ���r�������ڿ��з������ϲ�����ȻΪ���������ÿ�������ʼַΪ���շ���r�ĵ�ַ����СΪ����֮��
			else if (p->prior->date.flag != FREE && p->next->date.flag == FREE)
			{
				p->date.size += p->next->date.size;   //�ϲ�ǰ����������
				if (p->next->next)      //��һ�������������һ������
				{
					p->next->next->prior = p;
					p->next = p->next->next;
				}
				else
					p->next = p->next->next;
			}
			//3�����ղ���r�����¿��������ڣ���ʱ������������ϲ���ʼַΪr����������ĵ�ַ����СΪ����������С֮��
			else if (p->prior->date.flag == FREE && p->next->date.flag == FREE)
			{
				p->prior->date.size += p->date.size + p->next->date.size;
				if (p->next->next) //������һ���ڵ㲻�����һ���ڵ�
				{
					p->next->next->prior = p->prior;
					p->prior->next = p->next->next;
				}
				else p->prior->next = p->next->next;
			}
			//4�������ղ���r��������Ϊ�ǿ������򣬴�ʱ����һ���µĿ��з��������Ҽ��뵽������������ȥ
			else if (p->prior->date.flag != FREE && p->next->date.flag != FREE)
			{
				//ֻ�ðѽ���number��flag�ĳ�free������
			}
			cout << "���ճɹ���" << endl;
			getchar();
			getchar();
			return;
		}
		p = p->next;
		
	}
	cout << "û���ҵ���ҵ�ţ�" << endl;
	getchar();
	getchar();
}

void show()
{
	cout << endl;
	cout << "��ҵ�������" << endl;
	int i = 1;
	Free_Node* p = headNode->next;
	cout << "������" << "  ��ҵ��" << "\t��ʼ��ַ" << "    ��ҵ��С" << "   ����״̬" << endl;
	while (p)
	{
		cout << i++ << "\t " << p->date.number << '\t' << p->date.begin_address << "\t\t" << p->date.size << '\t';
		if (p->date.flag == FREE)
			cout << "����" << endl;
		else
			cout << "�ѷ���" << endl;
		p = p->next;
	}
	cout << "��Enter����" << endl;
	getchar();
	getchar();
}

int main()
{
	int tag = 0;
	int number;
	init();
	while (tag != 5)
	{	
		system("cls");
		cout << "�ڴ����ʵ�� ��ǰ�㷨��";
		if (algorithm_type == 1) {
			cout << "�״���Ӧ�㷨";
		}
		else if (algorithm_type == 2) {
			cout << "ѭ���״���Ӧ�㷨";
		}
		cout <<"\n��ѡ������� 1 - ������ҵ��2 - ��ҵ���գ�3 - ��ʾ��ҵ״����4 - �����㷨��5 - �˳�" << endl;
		cin >> tag;
		switch (tag)
		{
		case 1:
			allocation();
			break;
		case 2:
			cout << "��������Ҫ���յ���ҵ�ţ�" << endl;
			cin >> number;
			free(number);
			break;
		case 3:
			show();
			break;
		case 4:
			type_change();
			break;
		default:
			return 0;
		}
	}
	return 0;
}