/**
** 中缀表达式转换为后缀表达式
**/

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE  20
#define STACKINCREMENT 10
#define MAXBUFFER      10

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

int main() {
	sqStack s;
	char c, e;

	InitStack(&s);

	printf("请输入中缀表达式，以#作为结束标志：");
	scanf("%c", &c);

	while (c != '#') {
		//如果是数字，直接输出数字
		while (c >= '0' && c <= '9') {
			printf("%c", c);
			scanf("%c", &c);
			if (c < '0' || c > '9') {
				printf(" ");
			}
		}
		//如果是右括号，则将左括号到右括号之间所有符号出栈
		else if (')' == c) {
			Pop(&s, &e);
			while ('(' != e) {
				printf("%c", e);
				Pop(&s, &e);
			}
		}
		//如果是加或减号
		else if (c == '+' || c == '-') {
			if (!StackLen(s))
				Push(&s, c);
			else {
				do {
					Pop(&s, &e);
					if ('(' == e)
						Push(&s, e);
					else
						printf("%c", e);
				} while (StackLen(s) && '(' != e);
				Push(&s, c);
			}
		}
		//如果是*，/，（，直接入栈
		else if (c == '*' || c == '/' || c == '(')
			Push(&s, c);
		else if (c == '#')
			break;
		else {
			printf("输入错误\n");
			return -1;
		}

		scanf("%c", &c);
	}

	while (StackLen(s)) {
		Pop(&s, &e);
		printf("%c", e);
	}

	return 0;
}