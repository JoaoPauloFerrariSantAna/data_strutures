#include <stdio.h>
#include <stdlib.h> 

/* now let's try to create a stack with a dynamic array */

typedef int* Items;
typedef int StackLength;
typedef int StackNewLength;

const int stack_empty = 0;

StackLength stack_size = 5;
/* this will be used to sum with "stack_size" */
StackNewLength stack_new_limit = 4;

/* from what i've understood, it is better to create a struct */
/* because it is easier to keep track of the length */
typedef struct {
	int top;
	StackLength length;
	Items items;
} Stack; 

void copy_to(Items dest, Items source, int until) {
	for(int i = 0; i < until; i++) {
		/* copying the data to "dest" from "source" */
		dest[i] = source[i];
	}
}

Items resize(Items old_items, StackLength old_space, int space) {
	/* new size is just the old size plus some element */
	/* because if we just want 10 cookies, and we just have 5 */
	/* we will need to just get the amount that we have and */
	/* sum it with what is left to get to the 10 cookies */
	StackNewLength new_size = old_space + space;

	/* when we were creating "array" all that we did was just */
	/* get the size of an integer and multiply it with  */
	/* the amount of elements that we needed */
	/* it is the same thing here */
	Items new_items = malloc(sizeof(int) * new_size);

	/* copying elements to new array until the place */
	/* where the old one ended */
	copy_to(new_items, old_items, old_space + 1);

	/* clearing the memory of the old array... */
	free(old_items);

	return new_items;
}

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
		/* instead of the size of "stack->items" */
		/* we send the length, because then we will */
		/* have the actual amount of the array size */
		stack->items = resize(stack->items, stack->length, stack_new_limit);
		stack->length += stack_new_limit;
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
}

void stack_print(Stack* stack) {
	for(int i = 0; i < stack->length; i++) {
		printf("%d\n", stack->items[i]);
	}
}

int main() {
	Stack* stack = stack_create(stack_size);
	free(stack);
	stack = NULL;
	return 0;
}
