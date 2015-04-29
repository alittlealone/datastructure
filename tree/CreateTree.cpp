#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//创建一棵二叉树，约定用户遵照前序遍历方式输入数据
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