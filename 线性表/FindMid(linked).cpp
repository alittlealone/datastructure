/**
** ��Ѷ�����⣺�ҳ���������м���
** ˼�룺����ָ��
** ԭ����������ָ��*search,*mid��ָ�������ͷ�ڵ㣬����*search���ƶ��ٶ���*mid��2������*searchָ��ĩβ�ڵ��ʱ��mid�������м䣬Ҳ�Ǳ�ߵ�˼��
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