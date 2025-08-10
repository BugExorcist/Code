#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#define Size 200005
char ss[Size] { 0 };
int s[Size]{ 0 };
void d(int i)
{
    if (s[i] == 10)
    {
        s[i] = 0;
        s[i - 1]++;
        d(i - 1);
    }
}
int main()
{/*6位   010.245 5的下标是5 6是空的*/
    int n, t, point = -1, tail;
    cin >> n >> t;
    tail = n;/*tail是结束的位置*/
    cin >> ss;
    int cf = 0;
    for (int i = 1; i <= n; i++)
    {
        if (ss[i - 1] == '.')
        {
            point = i;/*记录小数点的位置*/
            cf = 1;
            continue;
        }
        s[i - cf] = ss[i - 1] - '0';
    }
    int flag = 0;
    while (1)
    {
        if (point == -1)
        {
            tail++;/*如果是整数，会少一个小数点的位置，让结尾长度+1 */
            break;/*如果给了个整数直接打印*/
        }
        for (int i = point; i < tail; i++)
        {
            if (s[i] >= 5)
                flag = 1;
            if (s[i] >= 5 && t > 0)
            {
                t--;
                s[i - 1]++;
                d(i - 1);
                tail = i;
            }
        }
        if (t < 1 || flag == 0)
        {
            break;
        }
        flag = 0;
    }
    if (s[0] != 0)
        cout << s[0];
    for (int i = 1; i < tail; i++)
    {
        if (i == point)
            cout << ".";
        cout << s[i];
    }
    cout << endl;
    return 0;
}

//看			不			懂
//#include<cstdio>
//#include<cstring>
//#include<cmath>
//#define N 1005
//struct point {
//    double x, y, r;
//}p[N];
//struct lr {
//    double d;
//    int i;
//}l[N], r[N];
//int n, fa[N], ll = 0, rr = 0;
//inline int find(int x) {
//    return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//void merge(int x, int y) {
//    int xx = find(x), yy = find(y);
//    if (xx != yy) fa[yy] = xx;
//}
//int main() {
//    //  freopen("a.in","r",stdin);
//    scanf("%d", &n);
//    for (int i = 0; i <= n + 1; ++i) fa[i] = i;//0--上边界,n+1--下边界 
//    // 输入n个圆心数据，并处理其与上下左右边界关系。
//    for (int i = 1; i <= n; ++i) {
//        scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].r);
//        if (p[i].y + p[i].r >= 1000) merge(i, 0);
//        if (p[i].y - p[i].r <= 0) merge(i, n + 1);
//        if (p[i].x - p[i].r <= 0) {
//            l[++ll].d = p[i].y - sqrt(pow(p[i].r, 2) - pow(p[i].x, 2));//与起点线的下交点 
//            l[ll].i = i;
//        }
//        if (p[i].x + p[i].r >= 1000) {
//            r[++rr].d = p[i].y - sqrt(pow(p[i].r, 2) - pow(1000 - p[i].x, 2));//与终点线的下交点
//            r[rr].i = i;
//        }
//    }
//    // 处理两圆相交的关系。
//    for (int i = 1; i < n; ++i) {
//        for (int j = i + 1; j <= n; ++j) {
//            if (p[i].r + p[j].r > sqrt(pow(p[i].x - p[j].x, 2) + pow(p[i].y - p[j].y, 2))) merge(i, j);
//        }
//    }
//    // 如果上边界与下边界联通，则一定过不去。
//    if (find(0) == find(n + 1)) printf("Bill will be bitten.\n");
//    else {// 如果能过，找最高点。
//        double lu = 1000, ru = 1000;
//        for (int i = 1; i <= ll; ++i)//与左边界、上边界均相交,l[i].d以上一定不能过
//            if (find(l[i].i) == find(0) && l[i].d < lu) lu = l[i].d;
//        for (int i = 1; i <= rr; ++i)
//            if (find(r[i].i) == find(0) && r[i].d < ru) ru = r[i].d;
//        printf("Bill enters at (0.00, %.2lf) and leaves at (1000.00, %.2lf).\n", lu, ru);
//    }
//    return 0;
//}




//这个方法噶了 拖走
//int map[1001][1001]{ 0 };
//int k;
//void DFS(int x, int y)
//{
//	//printf("(%d %d)->", x, y);
//	if (x == 1001)
//	{
//		printf("Bill enters at (0.00, %d.00) and leaves at (1000.00, %d.00).\n", k, y);
//		exit(-1);
//	}
//	else if (map[x][y] != 1)
//	{
//		map[x][y] = 1;
//		if (y + 1 <= 1000)
//			DFS(x, y + 1);
//		DFS(x + 1, y);
//		if (y - 1 >= 0)
//			DFS(x, y - 1);
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		int x, y, d;
//		cin >> x >> y >> d;
//		for (int j = -d + 1; j <= d; j++)
//		{
//			int a = x + j;
//			int b = y + j;
//			if (a >= 0 && a <= 1000 )
//			{
//				map[a][y] = 1;
//			}
//			if (b >= 0 && b <= 1000)
//			{
//				map[x][b] = 1;
//			}
//		}
//	}
//	for (k = 1000; k >= 0; k--)
//	{
//		DFS(0 ,k);
//	}
//	cout << "Bill will be bitten.\n" << endl;
//	return 0;
//}

//int main()
//{
//	char x;
//	int cnt = 0;
//	scanf("%c", &x);
//	while (x != '\n')
//	{
//		if (x == ' ')
//			cnt++;
//		else if (x == '#')
//			cnt += 2;
//		else if (x == 'z' || x == 's')
//			cnt += 4;
//		else
//		{
//			int n;
//			if(x < 's')
//				n = (x - 'a' + 1) % 3;
//			else
//				n = (x - 'a') % 3;
//			if (n == 0)
//				n += 3;
//			cnt += n;
//		}
//		scanf("%c", &x);
//	}
//	cout << cnt << endl;
//	return 0;
//}
//int main()
//{
//	char arr[100];
//	while (~scanf("%s", &arr))
//	{
//		int cnt = 0;
//		for (int i = 0; i < strlen(arr); i++)
//		{
//			cnt += arr[i] - 'a' + 1;
//		}
//		cout << cnt << endl;
//	}
//	return 0;
//}