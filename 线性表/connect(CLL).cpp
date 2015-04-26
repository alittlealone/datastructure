/**
** 链接A，B两个循环单链表
** 假设A,B为非空循环链表的尾指针
**/

LinkList Connect(LinkList A, LinkList B) {
	LinkList p = A->next; //保存A的头节点位置
	A->next = B->next->next; //B的开始节点链接到A表尾
	free(B->next); //释放B的头结点
	B->next = p;  //将B的尾指针指向A的头
	return B;  //返回新循环链表的尾指针
}