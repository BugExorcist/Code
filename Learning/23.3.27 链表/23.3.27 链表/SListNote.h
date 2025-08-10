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

//�����ӿ�
void SListPushBack(SLN** pphead, SLNDataTape x);//β��
void SListPushFront(SLN** pphead, SLNDataTape x);//ͷ��
void SListPopFront(SLN** pphead);//ͷɾ
void SListPopBack(SLN** pphead);//βɾ


SLN* SListFind(SLN* phead, SLNDataTape x);//����
void SListPrint(SLN* phead);//��ӡ
//��posλ��ǰ����x/ɾ��pos��ֵ
void SListInsert(SLN** pphead, SLN* pos, SLNDataTape x);//�������
void SListErase(SLN** pphead, SLN* pos);//���ɾ��




