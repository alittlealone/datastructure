//���мȿ���������ʵ�֣�Ҳ������˳���ʵ�֡�
//ջһ����˳���ʵ��
//���г�������ʵ�֣����������

typedef struct QNode {
	ElemType data;
	struct QNode *next;
}QNode, *QueuePrt;

typedef struct {
	QueuePrt front, rear;  //��ͷ��βָ��
}LinkQueue;