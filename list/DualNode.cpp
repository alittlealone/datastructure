//双向链表

typedef struct DualNode {
	ElemType data;
	struct DualNode *prior; //前驱结点
	struct DualNode *next;  //后继结点
}DualNode, *DuLinkList;