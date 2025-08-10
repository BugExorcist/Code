#include "Queue.h"

void QueueTest1()
{
	Q q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		cout << QueueFront(&q) << " ";
		QueuePop(&q);
	}

	QueueDestory(&q);
}

int main()
{
	QueueTest1();

	return 0;
}