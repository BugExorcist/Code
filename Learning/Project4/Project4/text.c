#define _CRT_SECURE_NO_WARNINGS 1

////ѡ�����
//#include <stdio.h>
//int main()
//{
//	int choice = 0;
//	printf("��Ҫ�ú�ѧϰ��\n");
//	printf("YES/NO>");
//	scanf("%c", &choice);
//	if (choice ="YES")
//		printf("���������۷�");
//	else printf("�ؼ��ֵ�");
//	return 0;
//}

//ѭ�����
//#include <stdio.h>
////whileѭ��
//int main()
//{
//	int code = 0;
//	while (code < 30000)
//	{
//		code++;
//		printf("д��%d�д���\n",code);
//	}
//	if (code >= 30000)
//	{
//		printf("Nice job.\n");
//	}
//	return 0;
//}

//����
#include<stdio.h>
//���庯��
int Add(int a, int b)
{
	int z = 0;
	z = a + b;
	return z;
}

int main()
{
	int a = 0, b = 0;
	printf("�����������ֽ��мӷ�����\n");
		scanf("%d %d", a,b);
		int sum = Add(a, b);
			printf("sum=%d\n",sum);

	return 0;
}
