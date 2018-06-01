typedef struct s_stack {
	int tab[100];
	char cursor;
} Stack ;


Stack* new_stack();
void push(int nb, Stack *stack);
int top(Stack *s);
int pop(Stack *s);

void print_stack(Stack *s);
