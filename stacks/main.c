#include <stdio.h>
#include <stdlib.h>

const int stack_max_size = 3;

const int stack_status_full = -5;
const int stack_status_ok = 1;

const int stack_place_start = -1;

typedef struct {
    int* head;
    int* items;
    int* tail;
    int icount;
} Stack;

Stack* stack_create() {
    stack* stack = malloc(sizeof(Stack));

    stack->items = malloc(sizeof(int) * stack_max_size);
    stack->head = stack_place_start;
    /* porque quando tem só uma pessoa na fila */
    /* ela é a primeira e última na fila */
    stack->tail = stack_place_start;
    /* porque não tem ningúem na fila ainda */
    stac->icount = 0;

    return q;
}

int push(stack* q, int value) {
    if(q->icount == stack_max_size) {
        return stack_status_full;
    }

    q->items[q->icount] = value;
    q->tail = q->tail + 1;
    q->icount++;

    return stack_status_ok;
}

void stack_print(stack* q) {
    for(int i = 0; i < q->icount; i++) {
        printf("- %d\n", q->items[i]);
    }
}

int main() {
    stack* stack = stack_create();

    if(push(stack, 1) == stack_status_full) {
        printf("stack is full.\n");
        return 1;
    }

    if(push(stack, 2) == stack_status_full) {
        printf("stack is full.\n");
        return 1;
    }

    if(push(stack, 3) == stack_status_full) {
        printf("stack is full.\n");
        return 1;
    }

    stack_print(stack);

    free(stack);
    stack = NULL;

    return 0;
}