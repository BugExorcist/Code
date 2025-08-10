#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <stdbool.h>
using namespace std;

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QN;

typedef struct Queue
{
	QN* head;
	QN* tail;
}Q;

void QueueInit(Q* q);
void QueueDestory(Q* q);

void QueuePush(Q* q, QDataType x);
void QueuePop(Q* q);
QDataType QueueBack(Q* q);
QDataType QueueFront(Q* q);
int QueueSize(Q* q);
bool QueueEmpty(Q* q);
