//双亲孩子表示法

#define MAX_TREE_SIZE 100

//孩子结点
typedef struct CTNode {
	int child;          //孩子结点下标
	struct CTNode *next;//指向下一个孩子结点的指针
}*ChildPtr;

//表头结构
typedef struct {
	ElemType data;
	int parent;
	ChildPtr firstchild;
}CTBox;

//树结构
typedef struct {
	CTBox nodes[MAX_TREE_SIZE]; //结点数组
	int r, n;
};