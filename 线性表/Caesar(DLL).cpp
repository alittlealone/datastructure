/**
** ˫������ʵ��
** Ҫ��ʵ���û�����һ����ʹ��2����ĸ�����з����仯�������û�����3����������
** DEFHIJKLMNOPQRSTUVWXYZABC
** ͬʱ��Ҫ֧�ָ�����������-3����������
** XYZABCDEFGHIJKLMNOPQRSTUVW
**/

#include <stdlib.h>
#include <stdio.h>

#define OK     1
#define ERROR  0

typedef char   ElemType;
typedef int    Status;

typedef struct DualNode {
	ElemType data;
	struct DualNode *prior;
	struct DualNode *next;
}DualNode, *DuLinkList;

Status InitList(DuLinkList *L) {
	DualNode *p, *q;
	int i;

	*L = (DuLinkList)malloc(sizeof(DualNode));
	if (!(*L))
		return ERROR;

	(*L)->next = (*L)->prior = NULL;
	p = (*L);

	for (i = 0; i < 26; i++) {
		q = (DualNode *)malloc(sizeof(DualNode));
		if (!q)
			return ERROR;

		//*L��ͷָ�룬����ֵ
		q->data = 'A' + i;
		q->prior = p;
		q->next = p->next;  //��Ҫֱ��дNULL���������
		p->next = q;

		p = q;
	}

	//��β����ѭ����������ͷ��㣩
	p->next = (*L)->next;
	(*L)->next->prior = p;

	return OK;
}

void Caesar(DuLinkList *L, int i) {
	if (i > 0) {
		do {
			(*L) = (*L)->next;
		} while (--i);
	}

	if (i < 0) {
		do {
			(*L) = (*L)->next;
		} while (++i);
	}
}

int main() {
	DuLinkList L;
	int i, n;

	InitList(&L);

	printf("������һ��������");
	scanf("%d", &n);
	printf("\n");
	Caesar(&L, n);

	for (i = 0; i < 26; i++) {
		L = L->next;
		printf("%c", L->data);
	}

	printf("\n");

	return 0;
}