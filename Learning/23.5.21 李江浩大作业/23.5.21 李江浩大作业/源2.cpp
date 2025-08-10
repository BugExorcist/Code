#include <iostream> 
using namespace std;

//#define MAX 100  // ͼ�ж�����������
//#define INF 0x3f3f3f3f  // �����ı�Ȩ��ֵ
//
//typedef struct
//{
//	int n;  // ͼ�ж��������
//	int e;  // ͼ�бߵ�����
//	char data[MAX];  // ���ڴ洢�����ǩ������
//	int edge[MAX][MAX];  // ���ڱ�ʾ�ڽӾ���Ķ�ά����
//} Graph;
//
//// ����ͼ�ĺ���
//void create(Graph& G, int n, int e)
//{
//	int i, j, k, w;
//	char a, b;
//
//	// ���붥���ǩ
//	for (i = 0; i < n; i++)
//		cin >> G.data[i];
//
//	// ��ʼ���ߵ�Ȩ��
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//		{
//			if (i == j)
//				G.edge[i][j] = 0;
//			else
//				G.edge[i][j] = INF;
//		}
//
//	// ����ߵ���Ϣ��Ȩ��
//	for (k = 0; k < e; k++)
//	{
//		cin >> a;
//		cin >> b;
//		cin >> w;
//
//		// �ҵ����� a �� b ������
//		for (i = 0; i < n; i++)
//			if (G.data[i] == a) break;
//		for (j = 0; j < n; j++)
//			if (G.data[j] == b) break;
//
//		// ���ڽӾ��������ñߵ�Ȩ��
//		G.edge[i][j] = w;
//		G.edge[j][i] = w;
//	}
//
//	G.n = n;
//	G.e = e;
//}
//
//// ִ�� Prim �㷨�ĺ���
//void P(Graph& G, int k)
//{
//	int l[MAX];  // �洢��С��Ȩ�ص�����
//	int c[MAX];  // �洢��ѡ�ڵ������
//	int i, j, count = 0;
//
//	// ��ʼ������ĳ�ʼֵ
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
//		// �ҵ�������С��Ȩ�ص���һ���ڵ�
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
//		// ���¼����ͱ�Ȩ��
//		int x = l[next];
//		count += l[next];
//		l[next] = 0;
//
//		// ������С��Ȩ�غͺ�ѡ�ڵ�
//		for (i = 0; i < G.n; i++)
//		{
//			if (l[i] > G.edge[next][i])
//			{
//				l[i] = G.edge[next][i];
//				c[i] = next;
//			}
//		}
//		// ��ӡѡ��ıߺ���ɱ�
//		printf("<%c->%c>\n", G.data[c[next]], G.data[next]);
//	}
//	printf("�ܻ��ѣ�%d\n", count);
//}
//
//int main()
//{
//	Graph g;
//	int n, e;
//	cin >> n >> e;
//	// ����ͼ
//	create(g, n, e);
//	// �Ӷ���0��ʼִ��Prim�㷨
//	P(g, 0);
//	return 0;
//}