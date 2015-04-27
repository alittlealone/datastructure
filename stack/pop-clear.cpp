//pop

Pop(sqStack *s, ElemType *e) {
	//Õ»ÒÑ¿Õ
	if (s->top == s->base)
		return;
	*e = *--(s->top);
}

//clear

ClearStack(sqStack *s){
	s->top = s->base;
}