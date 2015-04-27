/**
** 删除节点
**/

void delete(node **pNode, int i) {
	node *target;
	node *temp;
	int j = 1;

	if (i == 1) {
		//删除第一个节点
		//先找到最后一个节点
		for (target = *pNode; target->next != *pNode; target = target->next)
			;

		temp = *pNode;
		*pNode = (*pNode)->next;
		target->next = *pNode;
		free(temp);
	}
	else {
		//删除非第一个节点
		target = *pNode;

		for (; j < i - 1; ++j) {
			target = target->next;
		}

		temp = target->next;
		target->next = temp->next;
		free(temp);
	}
}