#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//���� ȥ֮��ʣ�µ�����
//���� ȥ֮ǰ������
int �ߺߺ߰���������������(int num)
{
	int add = (num + 1) * 2;
	return add;
}
int main()
{
	int time, num;
	scanf("%d %d", &time, &num);
	while(time--)
	{
		num = �ߺߺ߰���������������(num);
	}
	printf("%d", num);
	return 0;
}