#include <stdio.h>
#include <stdlib.h>

typedef int QueueLength;
typedef int QueueNewLength;
typedef int* Items;

QueueNewLength queue_new_limit = 2;
const int queue_empty = 0;

typedef struct {
	int back;
	/* because then we will need to update where the front is */
	int front;
	QueueLength length;
	Items items;
} Queue;

void queue_copy_to(Items dest, Items source, int until) {
	int i;
	for(i = 0; i < until; i++) {
		dest[i] = source[i];
	}
}

Items queue_resize(Items old_items, QueueLength old_space, int space) {
	QueueNewLength new_size = old_space + space;
	Items new_items = malloc(sizeof(int) * new_size);
	queue_copy_to(new_items, old_items, old_space + 1);
	free(old_items);
	return new_items;
}

Queue* queue_create(QueueLength length) {
	Queue* queue = malloc(sizeof(Queue));

	queue->front = 0;
	queue->back = 0;
	queue->length = length;
	queue->items = malloc(sizeof(int) * length);

	return queue;
}

void enqueue(Queue* queue, int value) {
	if(queue->front == queue->length) {
		queue->items = queue_resize(queue->items, queue->length, queue_new_limit);
		queue->length += queue_new_limit;
	}
	queue->items[queue->front] = value;
	/* we need to update the front to keep track of the current item */
	/* because the front is always the most recent one */
	queue->front++;
}

void dequeue(Queue* queue) {
	if(queue->length == queue_empty) {
		printf("Underflow of the queue.\n");
		return;
	}

	queue->length--;
	queue->front--;
	queue->items[queue->front] = 0;
}

void queue_print(Queue* queue) {
	int i;
	for(i = 0; i < queue->length; i++) {
		printf("%d\n", queue->items[i]);
	}
}

int main() {
	Queue* queue = queue_create(2);

	free(queue);
	queue = NULL;

	return 0;
}
