//ǰ�����������

visit(char c, int level) {
	printf("%c�ڵ�%d��\n", c, level);
}


PreOrderTraverse(BiTree T, int level) {
	if (T) {
		visit(T->data, level);
		PreOrderTraverse(T->lchild, level + 1);
		PreOrderTraverse(T->rchild, level + 1);
	}
}

///��main�����ж���level = 1