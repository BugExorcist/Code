#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	//�ַ���������(char)
//	char ch = 'a';//���ַ���a���Ž��С�ch��������
//	//����
//	int age = 19;
//	//������
//	short int num = 10;
//	short nun = 11;//�����ߣ�
// .0639+218STHYO��//	//�����ȸ���
//	float weight = 55.4;
//	//˫���ȸ���
//	double a = 0.05;
//
//	//��ӡһ������
//	printf("%d\n",100);
//	//sizeof-�ؼ���- ������-�������ͻ��߱�����ռ��С(����������)
//	printf("%d\n", sizeof(char));
//
//	return 0;
//}


//int main()
//{
//	//�ֶ�����һ������
//	int age = 15;
//	double weight = 75.3;
//
//	age = age + 1;
//	weight = weight+0.51;
//	//��ӡһ������ - %d 
//	//��ӡ������  float - %f double - %lf
//		printf("%d\n", age);
//		printf("%lf\n", weight);
//
//		return 0;
//}

//{�ֲ�����}ȫ�ֱ���
int a = 95; //ȫ�ֱ���
//int main()
//{
//	int a = 10;//�ֲ�����
//	printf("%d\n", a);
//	return 0;
//}

//���������ĺ�
//scanf <����>����
int main()
{
	int m = 0;//���Բ���ֵ�������Ƽ�
	int n = 0;
	int sum = 0;
	int �� = 0;
	scanf("%d %d", &m, &n);//���������	X X	��Ӧֵ(m n)
	sum = m + n;
	�� = m * n;
	printf("sum=%d\n", sum);
	printf("��=%d\n", ��);
	return 0;
}