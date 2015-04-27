/**
** 头插法建立单链表
**/

void CreateListHead(LinkList *L, int n) {
	LinkList p;
	int i;

	//初始化随机数种子
	srand(time(0));

	*L = (LinkList)malloc(sizeof(Node));
	//(*L)->next指向链表头部
	(*L)->next = NULL;

	for (i = 0; i < n; i++) {
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}