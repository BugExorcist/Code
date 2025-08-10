#include <iostream>
using namespace std;

#define FREE 0  // 表示空闲
#define  BUSY 1  // 表示已分配
#define  MAX_length 64  //空间大小


typedef struct free_area //首先定义空闲区分表结构
{
	int flag;//状态
	int size;//大小
	int number;//序号
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
pNod flagNode;//用于记录循环首次适应算法的开始节点
int allocation();//作业分配
void free(int number);//作业回收
bool ff(int number, int size);//首次适应算法
bool nf(int number, int size);//循环首次适应算法
void type_change();//更改算法类型
int algorithm_type = 1; //1->首次适应算法 2->循环首次适应算法
void show();//查看分配
void init();//初始化

void init()
{
	// 初始化空闲区链表
	headNode = new Free_Node;
	initNode = new Free_Node;
	flagNode = new Free_Node;
	// 初始化链表头结点和初始结点
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

//实现作业分配
int allocation()
{
	int number, size1;
	cout << "请输入作业号：";
	cin >> number;
	cout << "请输入所需作业大小：";
	cin >> size1;

	if (algorithm_type == 1)
	{
		if (ff(number, size1))
		{
			cout << "分配成功！" << endl;
		}
		else cout << "分配失败！" << endl;
	}
	else if (algorithm_type == 2)
	{
		if (nf(number, size1))
		{
			cout << "分配成功！" << endl;
		}
		else cout << "分配失败！" << endl;
	}
	getchar();
	getchar();
	return 1;
}

void type_change()
{
	int type;
	cout << "请选择更改的算法 1 - 首次适应算法，2 - 循环首次适应算法" << endl;
	cin >> type;
	if (type >= 1 && type <= 2)
	{
		algorithm_type = type;
	}
	else
	{
		cout << "无效参数！" << endl;
		type_change();
	}
}

bool ff(int number, int size)//首次适应算法
{
	pNod temp = new Free_Node;
	Free_Node* p = headNode->next;  //从首节点开始
	temp->date.number = number;
	temp->date.size = size;
	temp->date.flag = BUSY;
	while (p)
	{
		if (p->date.flag == FREE && p->date.size == size)//请求大小刚好满足
		{
			p->date.flag = BUSY;
			p->date.number = number;
			return true;
		}
		if (p->date.flag == FREE && p->date.size > size)//说明还有其他的空闲区间
		{
			temp->next = p;
			temp->prior = p->prior;
			temp->date.begin_address = p->date.begin_address;
			p->prior->next = temp;
			p->prior = temp;
			p->date.begin_address = temp->date.begin_address + temp->date.size;//空闲分区开始地址+此次分配的空间
			p->date.size -= size;      //分配空闲作业
			return true;
		}
		p = p->next;
	}
	return false;
}

bool nf(int number, int size) 
{
	pNod temp = new Free_Node;
	Free_Node* p = flagNode->next;  //从标记节点开始
	temp->date.number = number;
	temp->date.size = size;
	temp->date.flag = BUSY;
	while (p)
	{
		if (p->date.flag == FREE && p->date.size == size)//请求大小刚好满足
		{
			p->date.flag = BUSY;
			p->date.number = number;
			flagNode = p->prior;
			return true;
		}
		if (p->date.flag == FREE && p->date.size > size)//说明还有其他的空闲区间
		{
			temp->next = p;
			temp->prior = p->prior;
			temp->date.begin_address = p->date.begin_address;
			p->prior->next = temp;
			p->prior = temp;
			p->date.begin_address = temp->date.begin_address + temp->date.size;//空闲分区开始地址+此次分配的空间
			p->date.size -= size;      //分配空闲作业
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

void free(int number)//主存回收
{
	Free_Node* p = headNode->next;
	while (p)
	{
		if (p->date.number == number)//找到要回收的number区域
		{
			p->date.flag = FREE;
			p->date.number = FREE;
			//判断P与前后区域关系

			//1、回收分区r上临一个空闲分区，此时应该合并为一个连续的空闲区，其始址为r上相邻的分区的首地址，而大小为两者大小之和
			if (p->prior->date.flag == FREE && p->next->date.flag != FREE)
			{
				p->prior->date.size += p->date.size;
				p->prior->next = p->next;  //将要回收分区的前后两个分区链接起来
				p->next->prior = p->prior;
			}
			//2、回收分区r与下相邻空闲分区，合并后仍然为空闲区，该空闲区的始址为回收分区r的地址。大小为两者之和
			else if (p->prior->date.flag != FREE && p->next->date.flag == FREE)
			{
				p->date.size += p->next->date.size;   //合并前后两个分区
				if (p->next->next)      //下一个分区不是最后一个分区
				{
					p->next->next->prior = p;
					p->next = p->next->next;
				}
				else
					p->next = p->next->next;
			}
			//3、回收部分r与上下空闲区相邻，此时将这三个区域合并，始址为r上相邻区域的地址，大小为三个分区大小之和
			else if (p->prior->date.flag == FREE && p->next->date.flag == FREE)
			{
				p->prior->date.size += p->date.size + p->next->date.size;
				if (p->next->next) //如果最后一个节点不是最后一个节点
				{
					p->next->next->prior = p->prior;
					p->prior->next = p->next->next;
				}
				else p->prior->next = p->next->next;
			}
			//4、当回收部分r上下区域都为非空闲区域，此时建立一个新的空闲分区，并且加入到空闲区队列中去
			else if (p->prior->date.flag != FREE && p->next->date.flag != FREE)
			{
				//只用把结点的number和flag改成free就行了
			}
			cout << "回收成功！" << endl;
			getchar();
			getchar();
			return;
		}
		p = p->next;
		
	}
	cout << "没有找到作业号！" << endl;
	getchar();
	getchar();
}

void show()
{
	cout << endl;
	cout << "作业分配情况" << endl;
	int i = 1;
	Free_Node* p = headNode->next;
	cout << "分区号" << "  作业号" << "\t起始地址" << "    作业大小" << "   分区状态" << endl;
	while (p)
	{
		cout << i++ << "\t " << p->date.number << '\t' << p->date.begin_address << "\t\t" << p->date.size << '\t';
		if (p->date.flag == FREE)
			cout << "空闲" << endl;
		else
			cout << "已分配" << endl;
		p = p->next;
	}
	cout << "按Enter继续" << endl;
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
		cout << "内存管理实验 当前算法：";
		if (algorithm_type == 1) {
			cout << "首次适应算法";
		}
		else if (algorithm_type == 2) {
			cout << "循环首次适应算法";
		}
		cout <<"\n请选择操作： 1 - 申请作业，2 - 作业回收，3 - 显示作业状况，4 - 更改算法，5 - 退出" << endl;
		cin >> tag;
		switch (tag)
		{
		case 1:
			allocation();
			break;
		case 2:
			cout << "请输入需要回收的作业号：" << endl;
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