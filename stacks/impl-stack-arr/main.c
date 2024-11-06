#include <stdio.h>
#include <stdlib.h>

/* now, let's try to create a stack with an arr */

typedef int StackStatus;
typedef const int StackConstant;

StackConstant empty = 0;
StackConstant def_size = 5; 

StackStatus stack_limit_reached = -5;
StackStatus stack_empty = -4;
StackStatus stack_op_success = 1;

typedef struct {
	int top;
	int items[5];
} Stack;

Stack* stack_create() {
	Stack* stack = malloc(sizeof(Stack));

	stack->top = empty;

	return stack;
}

StackStatus push(Stack* stack, int value) {
	if(stack->top == def_size) {
		return stack_limit_reached;
	}

	stack->items[stack->top] = value;
	stack->top++;

	return stack_op_success;
}

StackStatus pop(Stack* stack) {
	if(stack->top == empty) {
		return stack_empty;
	}


	/* goes to the end of the stack */
	stack->items[stack->top - 1] = empty;

	stack->top--;
	return stack_op_success;
}
void stack_print(Stack* stack) {
	for(int i = 0; i < stack->top; i++) {
		printf("%d\n", stack->items[i]);
	}
}

int main() {
	Stack* stack = stack_create();


	if(push(stack, 1) == stack_limit_reached) {
		printf("Stack is full\n");
	}

	if(push(stack, 2) == stack_limit_reached) {
		printf("Stack is full\n");
	}

	if(pop(stack) == stack_empty) {
		printf("Stack is empty.\n");
	}

	stack_print(stack);

	return 0;
}
