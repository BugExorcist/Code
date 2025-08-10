#include<malloc.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
#define MaxInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
int cnt = 0;//记录花费
typedef struct
{
	VerTexType vex[MVNum];//顶点表
	ArcType arcs[MVNum][MVNum];//邻接矩阵
	int vexnum, arcnum;//图的当前点数和边数
}AMGraph;
struct
{
	VerTexType Head;//边的始点
	VerTexType Tail;//边的终点
	ArcType lowcost;//边上的权值
}Edge[MVNum];
int LocateVex(AMGraph& G, VerTexType u)
{//存在则返回u在顶点表中的下标;否则返回-1
	int i;
	for (i = 0; i < G.vexnum; ++i)
		if (u == G.vex[i])
			return i;
	//return -1;
}
void CreatUDN(AMGraph& G)//创建图
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
		cin >> v1 >> v2 >> c;                 //输入一条边依附的两个顶点及权值
		Edge[k].Head = v1;
		Edge[k].Tail = v2;
		Edge[k].lowcost = c;
		i = LocateVex(G, v1);  j = LocateVex(G, v2);
		G.arcs[i][j] = G.arcs[j][i] = c;
	}
}
typedef struct Closedge
{
	VerTexType adjvex;//最小边在U中的那个顶点
	ArcType lowcost;//最小边上的权值
}closedge[MVNum];
int Min(closedge SZ, AMGraph G)//求出第k个顶点，closedge[k]中存有当前最小边

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
int Vexset[MVNum];//辅助数组Vexset的定义
void kruskal(AMGraph G)//k算法
{//无向图G以邻接矩阵形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边
	int v1, v2, vs1, vs2;
	for (int i = 0; i < G.arcnum; i++) {//将Edge[100]中的元素按权值从小到大排序
		for (int j = 0; j < G.arcnum - 1 - i; j++) {
			if (Edge[j].lowcost > Edge[j + 1].lowcost) {
				Edge[G.arcnum + 2] = Edge[j];
				Edge[j] = Edge[j + 1];
				Edge[j + 1] = Edge[G.arcnum + 2];
			}
		}
	}
	for (int i = 0; i < G.vexnum; i++)//辅助数组，表示各顶点自成一个连通分量
	{
		Vexset[i] = i;
	}
	cout << "最小生成树各边为：" << endl;
	for (int i = 0; i < G.arcnum; i++)//依次查看数组Edge中的边
	{
		v1 = LocateVex(G, Edge[i].Head);//v1为边的始点Head的下标
		v2 = LocateVex(G, Edge[i].Tail);//v2为边的终点Tail的下标
		vs1 = Vexset[v1];//获取边Edge[i]的始点所在的连通分量vs1
		vs2 = Vexset[v2];//获取边Edge[i]的终点所在的连通分量vs2
		if (vs1 != vs2)//边的两个顶点分属不同的连通分量
		{
			cnt += Edge[i].lowcost;
			cout << Edge[i].Head << " " << Edge[i].Tail << " " << Edge[i].lowcost << endl;//输出此边
			for (int j = 0; j < G.vexnum; j++)//合并vs1和vs2两个分量，即两个统一编号
			{
				if (Vexset[j] == vs2) Vexset[j] = vs1;//集合编号为vs2的都改为vs1
			}
		}
	}
	cout << "总花费为：" << cnt << endl;
}

int main()
{
	AMGraph G;
	CreatUDN(G);
	kruskal(G);
	return 0;
}