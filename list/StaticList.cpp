//���Ա�ľ�̬����洢�ṹ
#define MAXSIZE 1000
typedef struct {
	ElemType data;  //����
	int cur;        //�α�
}Component, StaticLinkList[MAXSIZE];

//�Ծ�̬�����ʼ��
Status InitList(StaticLinkList space) {
	int i;
	for (i = 0; i < MAXSIZE - 1; i++) {
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

//��ÿ��з����±�
int Malloc_SLL(StaticLinkList space) {
	int i = space[0];
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}