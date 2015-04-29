#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//����һ�ö�������Լ���û�����ǰ�������ʽ��������
CreateBiTree(BiTree *T) {
	char c;

	scanf("%c", &c);
	if (c == ' ')
		*T = NULL;
	else {
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}