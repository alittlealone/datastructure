/**
** ��������
** һҪ���ڴ��д���һ��ͷ���
** ��Ҫ�����е�ͷָ���βָ�붼ָ��������ɵ�ͷ��㣬��Ϊ��ʱΪ�ն���
**/

initQueue(LinkQueue *q) {
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)
		exit(0);
	q->front->next = NULL;
}