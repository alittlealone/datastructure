/**
** ����A��B����ѭ��������
** ����A,BΪ�ǿ�ѭ�������βָ��
**/

LinkList Connect(LinkList A, LinkList B) {
	LinkList p = A->next; //����A��ͷ�ڵ�λ��
	A->next = B->next->next; //B�Ŀ�ʼ�ڵ����ӵ�A��β
	free(B->next); //�ͷ�B��ͷ���
	B->next = p;  //��B��βָ��ָ��A��ͷ
	return B;  //������ѭ�������βָ��
}