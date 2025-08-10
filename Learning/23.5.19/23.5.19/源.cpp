#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <iostream>
#include <math.h>
#define PI 3.14
using namespace std;
int main()
{
	
	return 0;
}

//int main()
//{
//	float a = 0, b = 0, c = 0, d = 0;
//	while (~scanf(" %f %f %f %f", &a, &b, &c, &d))
//	{
//		int Sa = 0, Sb = 0;
//		Sa = PI * a * a;
//		float p = (d + b + c) / 2;
//		Sb = sqrt(p * (p - b) * (p - c) * (p - d));
//		if (Sa > Sb)
//		{
//			cout << "A" << endl;
//		}
//		else
//		{
//			cout << "B" << endl;
//		}
//	}
//	return 0;
//}


//int main()
//{
//	int n, num, k;
//	while (~scanf("%d", &n))
//	{
//		int a = 0, b = 0, ad = 0, bd = 0;
//		while (n--)
//		{
//			cin >> num >> k;
//			if (k == 1)
//			{
//				a++;
//				ad += num;
//			}
//			else
//			{
//				b++;
//				bd += num;
//			}
//		}
//		int l = ad / a;
//		int r = bd / b;
//		printf("%d %d\r\n", l, r);
//	}
//	return 0;
//}
//float num = 0;
//int main()
//{
//	float n, arr[1000]{ 1,1,2 }, num = 0;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		num += arr[i + 1] / arr[i];
//		arr[i + 2] = arr[i + 1] + arr[i];
//	}
//	printf("%.2f\n", num);
//	return 0;
//}


//int main()
//{
//	float x, num = 0;
//	cin >> x;//需要计算奖金的部分
//	if (x > 1000000)
//	{
//		num += (x - 1000000) * 0.01;
//		x = 1000000;
//	}
//	if (x > 600000)
//	{
//		num += (x - 600000) * 0.015;
//		x = 600000;
//	}
//	if (x > 400000)
//	{
//		num += (x - 400000) * 0.03;
//		x = 400000;
//	}
//	if (x > 200000)
//	{
//		num += (x - 200000) * 0.05;
//		x = 200000;
//	}
//	if (x > 100000)
//	{
//		num += (x - 100000) * 0.075;
//		x = 100000;
//	}
//	num += x * 0.1;
//	cout << num << endl;
//	return 0;
//}

//int main()
//{
//	char x;
//	scanf("%c", &x);
//	int arr[4]{ 0 };
//	while (x != '\n')
//	{
//		if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
//		{
//			arr[0]++;
//		}
//		else if (x >= '0' && x <= '9')
//		{
//			arr[1]++;
//		}
//		else if (x == ' ')
//		{
//			arr[2]++;
//		}
//		else
//		{
//			arr[3]++;
//		}
//		scanf("%c", &x);
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << arr[3] << endl;
//	return 0;
//}