#include <iostream> 
using namespace std;

//#define MAX 100  // 图中顶点的最大数量
//#define INF 0x3f3f3f3f  // 无穷大的边权重值
//
//typedef struct
//{
//	int n;  // 图中顶点的数量
//	int e;  // 图中边的数量
//	char data[MAX];  // 用于存储顶点标签的数组
//	int edge[MAX][MAX];  // 用于表示邻接矩阵的二维数组
//} Graph;
//
//// 创建图的函数
//void create(Graph& G, int n, int e)
//{
//	int i, j, k, w;
//	char a, b;
//
//	// 输入顶点标签
//	for (i = 0; i < n; i++)
//		cin >> G.data[i];
//
//	// 初始化边的权重
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//		{
//			if (i == j)
//				G.edge[i][j] = 0;
//			else
//				G.edge[i][j] = INF;
//		}
//
//	// 输入边的信息和权重
//	for (k = 0; k < e; k++)
//	{
//		cin >> a;
//		cin >> b;
//		cin >> w;
//
//		// 找到顶点 a 和 b 的索引
//		for (i = 0; i < n; i++)
//			if (G.data[i] == a) break;
//		for (j = 0; j < n; j++)
//			if (G.data[j] == b) break;
//
//		// 在邻接矩阵中设置边的权重
//		G.edge[i][j] = w;
//		G.edge[j][i] = w;
//	}
//
//	G.n = n;
//	G.e = e;
//}
//
//// 执行 Prim 算法的函数
//void P(Graph& G, int k)
//{
//	int l[MAX];  // 存储最小边权重的数组
//	int c[MAX];  // 存储候选节点的数组
//	int i, j, count = 0;
//
//	// 初始化数组的初始值
//	for (i = 0; i < G.n; i++)
//	{
//		l[i] = G.edge[k][i];
//		c[i] = k;
//	}
//
//	for (j = 1; j < G.n; j++)
//	{
//		int next, t = 0;
//
//		// 找到具有最小边权重的下一个节点
//		for (i = 0; i < G.n; i++)
//		{
//			if (l[i] != 0)
//			{
//				if (t == 0)
//					next = i;
//				t++;
//				if (l[next] > l[i])
//					next = i;
//			}
//		}
//
//		// 更新计数和边权重
//		int x = l[next];
//		count += l[next];
//		l[next] = 0;
//
//		// 更新最小边权重和候选节点
//		for (i = 0; i < G.n; i++)
//		{
//			if (l[i] > G.edge[next][i])
//			{
//				l[i] = G.edge[next][i];
//				c[i] = next;
//			}
//		}
//		// 打印选择的边和其成本
//		printf("<%c->%c>\n", G.data[c[next]], G.data[next]);
//	}
//	printf("总花费：%d\n", count);
//}
//
//int main()
//{
//	Graph g;
//	int n, e;
//	cin >> n >> e;
//	// 创建图
//	create(g, n, e);
//	// 从顶点0开始执行Prim算法
//	P(g, 0);
//	return 0;
//}