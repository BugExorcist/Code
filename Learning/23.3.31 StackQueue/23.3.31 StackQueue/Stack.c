#include "Stack.h"


void StackInit(ST* ps)
{
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = -1;
}

void StackDestory(ST* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->top = -1;
	ps->capacity = 0;
}

//void CheckStack(ST* ps)
//{
//	if (ps->top == ps->capacity)
//	{
//		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			printf("realloc fail\n");
//			exit(-1);
//		}
//		else
//		{
//			ps->a = tmp;
//			ps->capacity *= 2;
//		}
//	}
//}

void StackPush(ST* ps, STDataType x)
{
	assert(ps);

	// ÂúÁË-¡·ÔöÈÝ
	if (ps->top == ps->capacity-1)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = tmp;
			ps->capacity *= 2;
		}
	}
	ps->top++;
	ps->a[ps->top] = x;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > -1);
	ps->top--;
}

STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > -1);

	return ps->a[ps->top];
}

int StcakSize(ST* ps)
{
	assert(ps);

	return ps->top + 1;
}

bool StcakEmpty(ST* ps)
{
	assert(ps);

	return ps->top == -1;
}