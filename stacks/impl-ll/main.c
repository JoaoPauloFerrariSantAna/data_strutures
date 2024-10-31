#include <stdio.h>
#include <stdlib.h>

typedef int StackStatus;
typedef int StackData;

const int stack_max_size = 3;

StackStatus stack_status_empty = -5;
StackStatus stack_status_ok = 1;

typedef struct StackElem {
    struct StackElem* next;
    StackData data;
} StackElem;

typedef struct {
    StackElem* head;
    int count;
} Stack;

Stack* stack_create() {
    Stack* stack = malloc(sizeof(Stack));

    stack->head = NULL;
    stack->count = 0;

    return stack;
}

void push(Stack* stack, int value) {
    StackElem* elem = malloc(sizeof(StackElem));

    elem->data = value;
    elem->next = stack->head;
    stack->head = elem;

    stack->count++;
}

StackStatus pop(Stack* stack) {
    StackElem* elems = malloc(sizeof(StackElem));
    StackElem* aux = stack->head;

    if(aux == NULL) {
        return stack_status_empty;
    }

    elems->next = NULL;

    /* go to the last element */
    while(aux->next->next != NULL) {
        aux = aux->next;
    }

    free(aux->next);
    aux->next = NULL;

    return stack_status_ok;
}

void stack_print(Stack* stack) {
    int i;

    printf("This stack has %d items.\n", stack->count);

    printf("-----------------------------------------\n");

    for(i = 0; i < stack->count; i++) {
        printf("- %d\n", stack->head->data);
        stack->head = stack->head->next;
    }

    printf("-----------------------------------------\n");
}

int main() {
    Stack* stack = stack_create();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    pop(stack);

    stack_print(stack);

    free(stack);
    stack = NULL;

    return 0;
}