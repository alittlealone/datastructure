/**
** 初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
** 操作结果：在L中第i个位置之前输入新的数据元素e，L长度+1
**/

Status ListInsert(SqList *L, int i, ElemType e) {
	int k;

	//线性表已满
	if (L->length == MAXSIZE) {
		return ERROR;
	}
	//i不在范围内，线性表从1开始
	if (i < 1 || i > L->length + 1) {
		return ERROR;
	}
	//插入位置不在表尾
	if (i <= L->length) {
		for (k = L->length - 1; k >= i - 1; k--) {
			L->data[k + 1] = L->data[k];
		}
	}

	L->data[i - 1] = e;
	L->length++;

	return OK;

}