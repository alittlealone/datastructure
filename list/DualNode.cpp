//˫������

typedef struct DualNode {
	ElemType data;
	struct DualNode *prior; //ǰ�����
	struct DualNode *next;  //��̽��
}DualNode, *DuLinkList;