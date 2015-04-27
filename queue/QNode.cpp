//队列既可以用链表实现，也可以用顺序表实现。
//栈一般用顺序表实现
//队列常用链表实现，简称链队列

typedef struct QNode {
	ElemType data;
	struct QNode *next;
}QNode, *QueuePrt;

typedef struct {
	QueuePrt front, rear;  //队头，尾指针
}LinkQueue;