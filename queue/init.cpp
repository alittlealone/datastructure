/**
** 创建队列
** 一要在内存中创建一个头结点
** 二要将队列的头指针和尾指针都指向这个生成的头结点，因为此时为空队列
**/

initQueue(LinkQueue *q) {
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)
		exit(0);
	q->front->next = NULL;
}