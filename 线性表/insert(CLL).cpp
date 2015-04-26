/**
** 插入节点
** 参数：链表的第一个节点，插入的位置
**/

void insert(node **pNode, int i) {
	//*pNode指向第一个节点
	node *temp;
	node *target;
	node *p;
	int item;
	int j = 1;

	printf("输入要插入的节点的值：");
	scanf("%d", &item);

	if (i == 1) {
		//新插入的节点作为第一个节点
		temp = (node*)malloc(sizeof(struct CLinkList));

		if (!temp)
			exit(0);

		temp->data = item;

		//寻找最后一个节点
		for (target = (*pNode); target->next != (*pNode); target = target->next)
			;

		temp->next = (*pNode);
		target->next = temp;
		*pNode = temp;
	}
	else{
		//不插入在第一个位置,找到要插入位置的前一个元素
		target = *pNode;

		for (; j < (i - 1); ++j)
			target = target->next;

		temp = (node*)malloc(sizeof(struct CLinkList));

		if (!temp)
			exit(0);

		temp->data = item;
		p = target->next;
		target->next = temp;
		temp->next = p;
	}
}