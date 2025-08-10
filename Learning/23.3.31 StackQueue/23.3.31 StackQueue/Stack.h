#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);

ST* CheckStack(ST* ps);

STDataType StackTop(ST* ps);
int StcakSize(ST* ps);
bool StcakEmpty(ST* ps);