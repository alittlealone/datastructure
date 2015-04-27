/**
** 腾讯面试题：找出单链表的中间结点
** 思想：快慢指针
** 原理：设置两个指针*search,*mid都指向单链表的头节点，其中*search的移动速度是*mid的2倍，当*search指向末尾节点的时候，mid正好在中间，也是标尺的思想
**/

Status FindMid(LinkList L, ElemType *e) {
	LinkList search, mid;
	mid = search = L;

	while (search->next != NULL) {
		if (search->next->next != NULL) {
			search = search->next->next;
			mid = mid->next;
		}else {
			search = search->next;
		}
	}

	*e = mid->data;

	return OK;
}