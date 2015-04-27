/**
** 初始化循环链表
**/

void init(node **pNode) {
	int item;
	node *temp;
	node *target;

	printf("输入节点的值，输入0完成初始化\n");

	while (1) {
		scanf("%d", &item);
		//清楚缓冲区
		fflush(stdin);

		if (item == 0)
			return;

		if ((*pNode) == NULL) {
			//循环列表只有一个节点
			*pNode = (node*)malloc(sizeof(struct ClinkList));

			if (!(*pNnode))
				exit(0);

			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		}
		else{
			//找到next指向第一个节点的节点
			for (target = (*pNode); target->next != (*pNode); target = target->next)
				;

			//生成一个新的节点
			temp = (node*)malloc(sizeof(struct CLinkList));

			if (!temp)
				exit(0);

			temp->data = item;
			temp->next = *pNode;
			target->next = temp;
		}
	}
}