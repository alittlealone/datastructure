/**
** ����ڵ�
** ����������ĵ�һ���ڵ㣬�����λ��
**/

void insert(node **pNode, int i) {
	//*pNodeָ���һ���ڵ�
	node *temp;
	node *target;
	node *p;
	int item;
	int j = 1;

	printf("����Ҫ����Ľڵ��ֵ��");
	scanf("%d", &item);

	if (i == 1) {
		//�²���Ľڵ���Ϊ��һ���ڵ�
		temp = (node*)malloc(sizeof(struct CLinkList));

		if (!temp)
			exit(0);

		temp->data = item;

		//Ѱ�����һ���ڵ�
		for (target = (*pNode); target->next != (*pNode); target = target->next)
			;

		temp->next = (*pNode);
		target->next = temp;
		*pNode = temp;
	}
	else{
		//�������ڵ�һ��λ��,�ҵ�Ҫ����λ�õ�ǰһ��Ԫ��
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