InsertQueue(cycleQueue *q, ElemType e) {
	if ((q->rear + 1) % MAXSIZE == q->front)
		return; //��������
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE;
}