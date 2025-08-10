#include <iostream> 
using namespace std;
#define MAX 500//���ڵ�����
#define INF 0x3f3f3f3f//�����

typedef struct //����һ��ͼ����
{
	int n;//�ڵ�����
	int e;//�ߵ�����
	char data[MAX];//�洢�ڵ�����
	int edge[MAX][MAX];//�洢�ڽӾ���
}Graph;

void create(Graph& G, int n, int e)//����ͼ
{
	int i, j, k, w;
	char a, b;
	for (i = 0; i < n; i++)//����ڵ�����
		cin >> G.data[i];
	for (i = 0; i < n; i++)//��ʼ��ͼ
		for (j = 0; j < n; j++)
		{
			if (i == j)
				G.edge[i][j] = 0;//�ڵ㵽�Լ�������0
			else
				G.edge[i][j] = INF;//�ڵ�֮����������
		}
	for (k = 0; k < e; k++)//���벻ͬ�ڵ���������
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

void Prim(Graph& G, int k)//Prim�㷨��С������
{
	int lowcost[MAX];//��ѡȨֵ
	//0��Ϊ�Ѿ�ѡ�뼯��U ����ֵ��ʾ�����ѡ��V�����нڵ����СȨֵ INF��ʾ�����
	int cddnode[MAX];//��ѡ�ߵ���ʼ�ڵ��±�
	int i, j, count = 0;
	for (i = 0; i < G.n; i++)
	{
		lowcost[i] = G.edge[k][i];
		cddnode[i] = k;
	}
	cout << "�ɱ���С�ı��У�" << endl;
	for (j = 1; j < G.n; j++)//Ѱ����С��n-1����
	{
		int next, t = 0;//next��ʾ��һ�����ߵĽڵ��±�
		for (i = 0; i < G.n; i++)//Ѱ��next
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
		int x = lowcost[next];//��¼�ߵĳɱ�
		count += lowcost[next];//��¼�ɱ�
		lowcost[next] = 0;//next����뼯��U
		for (i = 0; i < G.n; i++)//���º�ѡȨֵ�ͺ�ѡ�ߵ���ʼ�ڵ�
		{
			if (lowcost[i] > G.edge[next][i])
			{
				lowcost[i] = G.edge[next][i];
				cddnode[i] = next;
			}
		}
		cout << "(" << G.data[cddnode[next]] << "," << G.data[next] << ") �ɱ��ǣ�" << x << endl;//��ӡ��
	}
	cout <<"��С�ɱ�Ϊ��" << count << endl;//��ӡ�ɱ�
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