//³ö¶ÓÁÐ
DeleteQueue(LinkQueue *q, ElemType *e) {
	QueuePtr p;
	if (q->front == q->rear)
		return;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)
		q->rear = q->front;
	free(p);
}