/**
** 双向链表实现
** 要求实现用户输入一个数使得2个字母的排列发生变化，例如用户输入3，输出结果：
** DEFHIJKLMNOPQRSTUVWXYZABC
** 同时需要支持负数，如输入-3，输出结果：
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

		//*L是头指针，不赋值
		q->data = 'A' + i;
		q->prior = p;
		q->next = p->next;  //不要直接写NULL，程序不灵活
		p->next = q;

		p = q;
	}

	//首尾构成循环（不包括头结点）
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

	printf("请输入一个整数：");
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