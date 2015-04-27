/**
** 初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
** 操作结果：在L中第i个位置之前输入新的数据元素e，L长度+1
**/

Status ListInsert(LinkList *L, int i, ElemType e) {
	int j;
	LinkList p, s;

	p = *L;
	j = 1;

	while (p && j < i) {
		p = p->next;
		j++;
	}

	if (!p || j > i) {
		return ERROR;
	}

	s = (LinkList)malloc(sizeof(Node));
	s->data = e;

	s->next = p->next;
	p->next = s;

	return OK;
}