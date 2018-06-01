#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int test(){

	Stack *stack = new_stack();
	push(10, stack);
	push(30, stack);
	push(-52, stack);
	print_stack(stack);
	int a = pop(stack);
	printf("\npoped : %d", a);
	print_stack(stack);
	int b = pop(stack);
	printf("\npoped : %d", b);
	push(666, stack);
	print_stack(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	pop(stack);
	print_stack(stack);


}
/*
int main(void){

	puts("Lancement test");
	test();
	return 0 ;
}
*/
void print_stack(Stack *s){
	int i = 0 ;
	printf("\n");
	for(putchar('|');i<(top(s));i++) printf("%d ", s->tab[i]);
	printf("|\n");

}

Stack* new_stack(){
	Stack *n = (Stack*)malloc(sizeof(Stack));
	n->cursor = 0 ;
	return n;
}

void push(int nb, Stack *s){
	s->tab[s->cursor++] = nb ;
}

int top(Stack *s){
	return s->cursor ;
}

int pop(Stack *s){
	if(!s->cursor) return -1;
	return s->tab[--s->cursor];	
}

