/**
** ��ʼ��ѭ������
**/

void init(node **pNode) {
	int item;
	node *temp;
	node *target;

	printf("����ڵ��ֵ������0��ɳ�ʼ��\n");

	while (1) {
		scanf("%d", &item);
		//���������
		fflush(stdin);

		if (item == 0)
			return;

		if ((*pNode) == NULL) {
			//ѭ���б�ֻ��һ���ڵ�
			*pNode = (node*)malloc(sizeof(struct ClinkList));

			if (!(*pNnode))
				exit(0);

			(*pNode)->data = item;
			(*pNode)->next = *pNode;
		}
		else{
			//�ҵ�nextָ���һ���ڵ�Ľڵ�
			for (target = (*pNode); target->next != (*pNode); target = target->next)
				;

			//����һ���µĽڵ�
			temp = (node*)malloc(sizeof(struct CLinkList));

			if (!temp)
				exit(0);

			temp->data = item;
			temp->next = *pNode;
			target->next = temp;
		}
	}
}