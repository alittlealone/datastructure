//线性表的静态链表存储结构
#define MAXSIZE 1000
typedef struct {
	ElemType data;  //数据
	int cur;        //游标
}Component, StaticLinkList[MAXSIZE];

//对静态链表初始化
Status InitList(StaticLinkList space) {
	int i;
	for (i = 0; i < MAXSIZE - 1; i++) {
		space[i].cur = i + 1;
	}
	space[MAXSIZE - 1].cur = 0;
	return OK;
}

//获得空闲分量下标
int Malloc_SLL(StaticLinkList space) {
	int i = space[0];
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;
}