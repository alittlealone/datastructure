//´´½¨Ë³ÐòÕ»

#define STACK_INIT_SIZE 100

typedef struct {
	ElemType *base;
	ElemType *top;
	int stackSize;
}sqStack;

initStack(sqStack *s) {
	s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	if (!s->base)
		exit(0);
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}