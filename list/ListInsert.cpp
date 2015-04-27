/**
** ��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
** �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L����+1
**/

Status ListInsert(SqList *L, int i, ElemType e) {
	int k;

	//���Ա�����
	if (L->length == MAXSIZE) {
		return ERROR;
	}
	//i���ڷ�Χ�ڣ����Ա��1��ʼ
	if (i < 1 || i > L->length + 1) {
		return ERROR;
	}
	//����λ�ò��ڱ�β
	if (i <= L->length) {
		for (k = L->length - 1; k >= i - 1; k--) {
			L->data[k + 1] = L->data[k];
		}
	}

	L->data[i - 1] = e;
	L->length++;

	return OK;

}