#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//int main()
//{
//	int n, x;
//	scanf("%d", &n);
//	printf("%d", (n * 1024 * 1024 / 4));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d %d %d", &a, &b, &c);
//	printf("%g", (a * 0.2 + b * 0.3 + c * 0.5));
//	return 0;
//}

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//	int a, b, c, d;
//	scanf("%d %d %d %d", &a, &b, &c, &d);
//	int arr[4] = { a,b,c,d };
//	for (int i = 1; i < 4; i++)
//	{
//		int tem = arr[i], time = i - 1;
//		while (time >= 0)
//		{
//			if (tem < arr[time])
//			{
//				arr[time + 1] = arr[time];
//				time--;
//			}
//			else
//			{
//				break;
//			}
//			
//			arr[time + 1] = tem;
//		}
//	}
//	printf("%d", abs((arr[0] + arr[3]) - (arr[1] + arr[2])));
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int a, b, c, d;
//	scanf("%d %d %d %d", &a, &b, &c, &d);
//	int arr[4] = { a,b,c,d };
//	for (int i = 1; i < 4; i++)
//	{
//		int tem = arr[i], time = i - 1;
//		//�ӵڶ�������ʼ��ǰ�Ƚ�    arr[i]�Ǵ������Ԫ��
//		while (time >= 0)
//		{
//			//�Ȳ�������ִ�������              
//			if (tem < arr[time])
//			{
//				arr[time + 1] = arr[time];
//				time--;
//			}
//			else
//			{
//				break;
//			}
//			printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
//			//����Ȳ��������С���ߴ�������������С������������
//			arr[time + 1] = tem;
//		}
//		printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
//	}
//
//	return 0;
//}