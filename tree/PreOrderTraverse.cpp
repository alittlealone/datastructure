//前序遍历二叉树

visit(char c, int level) {
	printf("%c在第%d层\n", c, level);
}


PreOrderTraverse(BiTree T, int level) {
	if (T) {
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level + 1);
		PreOrderTraverse(T->rchild, level + 1);
	}
}

///在main函数中定义level = 1