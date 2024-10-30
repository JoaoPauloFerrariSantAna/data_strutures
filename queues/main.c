#include <stdio.h>
#include <stdlib.h>

const int queue_max_size = 3;

const int queue_full = -5;
const int queue_ok = 1;

typedef struct {
    int* head;
    int* items;
    int* tail;
    int icount;
} Queue;

Queue* queue_create() {
    Queue* q = malloc(sizeof(Queue));

    q->items = malloc(sizeof(int) * queue_max_size);
    q->head = &q->items[0];
    /* porque quando tem só uma pessoa na fila */
    /* ela é a primeira e última na fila */
    q->tail = q->head;
    /* porque não tem ningúem na fila ainda */
    q->icount = 0;

    return q;
}

int push(Queue* q, int value) {
    if(q->icount == queue_max_size) {
        return queue_full;
    }

    q->items[q->icount] = value;
    q->tail = q->tail + 1;
    q->icount++;

    return queue_ok;
}

void queue_print(Queue* q) {
    for(int i = 0; i < q->icount; i++) {
        printf("- %d\n", q->items[i]);
    }
}

int main() {
    Queue* queue = queue_create();

    if(push(queue, 1) == queue_full) {
        printf("Queue is full.\n");
        return 1;
    }

    if(push(queue, 2) == queue_full) {
        printf("Queue is full.\n");
        return 1;
    }

    if(push(queue, 3) == queue_full) {
        printf("Queue is full.\n");
        return 1;
    }

    queue_print(queue);

    free(queue);
    queue = NULL;

    return 0;
}