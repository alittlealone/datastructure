//进制转换
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_INIT_SIZE  20
#define STACKINCREMENT 10

typedef char ElemType;
typedef struct {
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

void InitStack(sqStack *s) {
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
		exit(0);
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

Push(sqStack *s, ElemType e) {
	if (s->top - s->base >= s->stackSize) {
		s->base = (ElemType *)realloc(s->base, (s->stackSize + STACKINCREMENT) * sizeof(ElemType));
		if (!s->base)
			exit(0);

		s->top = s->base + s->stackSize;   //设置栈顶
		s->stackSize = s->stackSize + SATCKINCREMENT; //设置栈的最大容量
	}

	*(s->top) = e;
	s->top++;
}

Pop(sqStack *s, ElemType *e) {
	if (s->top == s->base)
		return;
	*e = *--(s->top);
}

int StackLen(sqStack s) {
	return (s.top - s.base);
}

int main(){
	ElemType c;
	sqStack s;
	int len, i, sum = 0;

	InitStack(&s);

	printf("请输入二进制数，输入#符号表示结束\n");
	scanf("%c", &c);
	while (c != '#') {
		Push(&s, c);
		scanf("%c", &c);
	}
	
	getchar();

	len = StackLen(s);
	printf("栈的当前容量是%d\n", &len);

	for (i = 0; i < len; i++) {
		Pop(&s, &c);
		sum = sum + (c - 48) * pow(2, i);
	}

	printf("转化为十进制数为%d\n", sum);
	return 0;
}