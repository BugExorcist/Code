#include "Queue.h"

void QueueInit(Q* q)
{
	assert(q);
	q->head = q->tail = NULL;
}

void QueueDestory(Q* q)
{
	QN* cur = q->head;
	while (cur)
	{
		QN* next = cur->next;
		free(cur);
		cur = next;
	}
	q->head = q->tail = NULL;
}

void QueuePush(Q* q, QDataType x)
{
	assert(q);

	QN* newnode = (QN*)malloc(sizeof(QN));
	if (newnode == NULL)
	{
		cout << "malloc fail" << endl;
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (q->tail == NULL)
	{
		q->head = q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
}

void QueuePop(Q* q)
{
	assert(q);
	assert(q->head);

	if (q->head->next == NULL)
	{
		free(q->head);
		q->head = q->tail = NULL;
	}
	else
	{
		QN* next = q->head->next;
		free(q->head);
		q->head = next;
	}
}

QDataType QueueBack(Q* q)
{
	assert(q);
	assert(q->tail );

	return q->tail->data;
}

QDataType QueueFront(Q* q)
{
	assert(q);
	assert(q->head);

	return q->head->data;
}

int QueueSize(Q* q)
{
	assert(q);

	int size = 0;
	QN* cur = q->head;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return size;
}

bool QueueEmpty(Q* q)
{
	assert(q);

	return q->head == NULL;
}
