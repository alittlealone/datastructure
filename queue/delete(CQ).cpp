DeleteQueue(cycleQueue *q, ElemType *e) {
	if (q->front == q->rear)
		return;   //╤сапн╙©у
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXSIZE;
}