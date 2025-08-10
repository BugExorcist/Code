#include <iostream> 
using namespace std;
#define MAX 500//最大节点数量
#define INF 0x3f3f3f3f//无穷大

typedef struct //创建一个图类型
{
	int n;//节点数量
	int e;//边的数量
	char data[MAX];//存储节点名称
	int edge[MAX][MAX];//存储邻接矩阵
}Graph;

void create(Graph& G, int n, int e)//生成图
{
	int i, j, k, w;
	char a, b;
	for (i = 0; i < n; i++)//输入节点名称
		cin >> G.data[i];
	for (i = 0; i < n; i++)//初始化图
		for (j = 0; j < n; j++)
		{
			if (i == j)
				G.edge[i][j] = 0;//节点到自己距离是0
			else
				G.edge[i][j] = INF;//节点之间距离无穷大
		}
	for (k = 0; k < e; k++)//输入不同节点间距离数据
	{
		cin >> a;
		cin >> b;
		cin >> w;
		for (i = 0; i < n; i++)
			if (G.data[i] == a) break;
		for (j = 0; j < n; j++)
			if (G.data[j] == b) break;
		G.edge[i][j] = w;
		G.edge[j][i] = w;
	}
	G.n = n;
	G.e = e;
}

void Prim(Graph& G, int k)//Prim算法最小生成树
{
	int lowcost[MAX];//候选权值
	//0视为已经选入集合U 其他值表示到达候选点V集合中节点的最小权值 INF表示无穷大
	int cddnode[MAX];//候选边的起始节点下标
	int i, j, count = 0;
	for (i = 0; i < G.n; i++)
	{
		lowcost[i] = G.edge[k][i];
		cddnode[i] = k;
	}
	cout << "成本最小的边有：" << endl;
	for (j = 1; j < G.n; j++)//寻找最小的n-1条边
	{
		int next, t = 0;//next表示下一次连线的节点下标
		for (i = 0; i < G.n; i++)//寻找next
		{
			if (lowcost[i] != 0)
			{
				if (t == 0)
					next = i;
				t++;
				if (lowcost[next] > lowcost[i])
					next = i;
			}
		}
		int x = lowcost[next];//记录边的成本
		count += lowcost[next];//记录成本
		lowcost[next] = 0;//next点加入集合U
		for (i = 0; i < G.n; i++)//更新候选权值和候选边的起始节点
		{
			if (lowcost[i] > G.edge[next][i])
			{
				lowcost[i] = G.edge[next][i];
				cddnode[i] = next;
			}
		}
		cout << "(" << G.data[cddnode[next]] << "," << G.data[next] << ") 成本是：" << x << endl;//打印边
	}
	cout <<"最小成本为：" << count << endl;//打印成本
}

int main()
{
	Graph my;
	int n, e;
	cin >> n >> e;
	create(my, n, e);
	Prim(my, 0);
	return 0;
}