#include <stdio.h>
#include <stdlib.h> 

/* now let's try to create a stack with a dynamic array */

const int stack_empty = 0;

/* from what i've understood, it is better to create a struct */
/* because it is easier to keep track of the length */
typedef struct {
	int top;
	int length;
	int* items;
} Stack; 

Stack* stack_create(int init_length) {
	Stack* stack = malloc(sizeof(Stack));

	/* we need the top empty because then we will update this  */
	/* on pushes and pops */
	stack->top = stack_empty;
	stack->length = init_length;
	stack->items = malloc(sizeof(int) * init_length);

	return stack;
}

void push(Stack* stack, int value) {
	if(stack->top == stack->length) {
		printf("Overflow of the stack.\n");
		return;
	}

	stack->items[stack->top] = value;

	/* (this is more for me) */
	/* we need to update the head because the inserted value */
	/* is always the most recent one */
	/* so it is "stack->top" */
	stack->top++;
}

void pop(Stack* stack) {
	if(stack->length == stack_empty) {
		printf("Underflow of the stack.\n");
		return;
	}

	stack->top--;
	stack->length--;

	printf("Erasing top...\n");
}

void stack_print(Stack* stack) {
	for(int i = 0; i < stack->length; i++) {
		printf("%d\n", stack->items[i]);
	}
}

int main() {
	const int stack_size = 5;
	Stack* stack = stack_create(stack_size);

	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);

	pop(stack);
	pop(stack);
	pop(stack);

	stack_print(stack);

	free(stack);
	stack = NULL;

	return 0;
}
