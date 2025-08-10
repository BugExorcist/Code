#include<malloc.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
int cnt = 0;//��¼����
typedef struct
{
	VerTexType vex[MVNum];//�����
	ArcType arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;//ͼ�ĵ�ǰ�����ͱ���
}AMGraph;
struct
{
	VerTexType Head;//�ߵ�ʼ��
	VerTexType Tail;//�ߵ��յ�
	ArcType lowcost;//���ϵ�Ȩֵ
}Edge[MVNum];
int LocateVex(AMGraph& G, VerTexType u)
{//�����򷵻�u�ڶ�����е��±�;���򷵻�-1
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (u == G.vex[i])
			return i;
	//return -1;
}
void CreatUDN(AMGraph& G)//����ͼ
{
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++)
		cin >> G.vex[i];
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = MaxInt;
	}
	for (int k = 0; k < G.arcnum; k++)
	{
		int i, j;
		char v1, v2;
		int c;
		cin >> v1 >> v2 >> c;                 //����һ�����������������㼰Ȩֵ
		Edge[k].Head = v1;
		Edge[k].Tail = v2;
		Edge[k].lowcost = c;
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		G.arcs[i][j] = G.arcs[j][i] = c;
	}
}
typedef struct Closedge
{
	VerTexType adjvex;//��С����U�е��Ǹ�����
	ArcType lowcost;//��С���ϵ�Ȩֵ
}closedge[MVNum];
int Min(closedge SZ, AMGraph G)//�����k�����㣬closedge[k]�д��е�ǰ��С��

{
	int i = 0, j, k, min;
	while (!SZ[i].lowcost)
		i++;
	min = SZ[i].lowcost;
	k = i;
	for (j = i + 1; j < G.vexnum; j++)
	{
		if (SZ[j].lowcost > 0)
		{
			if (min > SZ[j].lowcost)
			{
				min = SZ[j].lowcost;
				k = j;
			}
		}
	}
	return k;
}
int Vexset[MVNum];//��������Vexset�Ķ���
void kruskal(AMGraph G)//k�㷨
{//����ͼG���ڽӾ�����ʽ�洢���Ӷ���u��������G����С������T�����T�ĸ�����
	int v1, v2, vs1, vs2;
	for (int i = 0; i < G.arcnum; i++) {//��Edge[100]�е�Ԫ�ذ�Ȩֵ��С��������
		for (int j = 0; j < G.arcnum - 1 - i; j++) {
			if (Edge[j].lowcost > Edge[j + 1].lowcost) {
				Edge[G.arcnum + 2] = Edge[j];
				Edge[j] = Edge[j + 1];
				Edge[j + 1] = Edge[G.arcnum + 2];
			}
		}
	}
	for (int i = 0; i < G.vexnum; i++)//�������飬��ʾ�������Գ�һ����ͨ����
	{
		Vexset[i] = i;
	}
	cout << "��С����������Ϊ��" << endl;
	for (int i = 0; i < G.arcnum; i++)//���β鿴����Edge�еı�
	{
		v1 = LocateVex(G, Edge[i].Head);//v1Ϊ�ߵ�ʼ��Head���±�
		v2 = LocateVex(G, Edge[i].Tail);//v2Ϊ�ߵ��յ�Tail���±�
		vs1 = Vexset[v1];//��ȡ��Edge[i]��ʼ�����ڵ���ͨ����vs1
		vs2 = Vexset[v2];//��ȡ��Edge[i]���յ����ڵ���ͨ����vs2
		if (vs1 != vs2)//�ߵ��������������ͬ����ͨ����
		{
			cnt += Edge[i].lowcost;
			cout << Edge[i].Head << " " << Edge[i].Tail << " " << Edge[i].lowcost << endl;//����˱�
			for (int j = 0; j < G.vexnum; j++)//�ϲ�vs1��vs2����������������ͳһ���
			{
				if (Vexset[j] == vs2) Vexset[j] = vs1;//���ϱ��Ϊvs2�Ķ���Ϊvs1
			}
		}
	}
	cout << "�ܻ���Ϊ��" << cnt << endl;
}

int main()
{
	AMGraph G;
	CreatUDN(G);
	kruskal(G);
	return 0;
}