DestroyStack(sqStack *s) {
	int i, len;
	len = s->stackSize;
	for (i = ; i < len; i++){
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->stackSize = 0;
}