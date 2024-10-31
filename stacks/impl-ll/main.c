#include <stdio.h>
#include <stdlib.h>

typedef int StackStatus;
typedef int StackData;

const int stack_max_length = 3;

StackStatus stack_status_empty = -5;
StackStatus stack_max_reached = -4;
StackStatus stack_status_ok = 1;

typedef struct StackElem {
    struct StackElem* next;
    StackData data;
} StackElem;

typedef struct {
    StackElem* head;
    int length;
} Stack;

Stack* stack_create() {
    Stack* stack = malloc(sizeof(Stack));
    stack->head = NULL;
    stack->length = 0;
    return stack;
}

StackStatus push(Stack* stack, int value) {
    StackElem* elem = NULL;

	if(stack->length == stack_max_length) {
		return stack_max_reached;
	}

	elem = malloc(sizeof(StackElem));
    elem->data = value;
    elem->next = stack->head;
    stack->head = elem;
    stack->length++;

	return stack_status_ok;
}

StackStatus pop(Stack* stack) {
    StackElem* aux = NULL;

    if(stack->head == NULL) {
        return stack_status_empty;
    }

    aux = stack->head;

    /* checks if the next stack element after the current is the end */
    while(aux->next->next != NULL) {
        aux = aux->next;
    }

    free(aux->next);
    aux->next = NULL;
    stack->length--;

    return stack_status_ok;
}

void stack_print(Stack* stack) {
	StackElem* elemns = stack->head;
    int i;

    printf("This stack has %d items.\n", stack->length);

    printf("-----------------------------------------\n");

    for(i = 0; i < stack->length; i++) {
        printf("- %d\n", elemns->data);
        elemns = elemns->next;
    }

    printf("-----------------------------------------\n");
}

int main() {
    Stack* stack = stack_create();

    if(push(stack, 1) == stack_max_reached) {
		printf("max_size has been reached.\n");
	}

    if(push(stack, 2) == stack_max_reached) {
		printf("max_size has been reached.\n");
	}

    if(push(stack, 3) == stack_max_reached) {
		printf("max_size has been reached.\n");
	}

	if(push(stack, 4) == stack_max_reached) {
		printf("max_size has been reached.\n");
	}

    pop(stack);

    stack_print(stack);

    free(stack);
    stack = NULL;

    return 0;
}
