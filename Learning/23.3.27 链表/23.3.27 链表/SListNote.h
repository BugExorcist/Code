#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int SLNDataTape;

typedef struct SListNote
{
	SLNDataTape date;
	struct SListNote* next;
}SLN;

//声明接口
void SListPushBack(SLN** pphead, SLNDataTape x);//尾插
void SListPushFront(SLN** pphead, SLNDataTape x);//头插
void SListPopFront(SLN** pphead);//头删
void SListPopBack(SLN** pphead);//尾删


SLN* SListFind(SLN* phead, SLNDataTape x);//查找
void SListPrint(SLN* phead);//打印
//在pos位置前插入x/删除pos的值
void SListInsert(SLN** pphead, SLN* pos, SLNDataTape x);//随机插入
void SListErase(SLN** pphead, SLN* pos);//随机删除




