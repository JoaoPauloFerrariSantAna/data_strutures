#include <stdio.h>
#include <stdlib.h>

const int magic_size = 5;

typedef struct {
	/* because i want to know of who enters first */
	int* head;
	int* elements;
	/* because i want to know of who enters last */
	int* tail;
} Queue;

Queue* queue_create(int length) {
	Queue* queue = malloc(sizeof(Queue));

	queue->elements = malloc(sizeof(int) * length);
	queue->head = &queue->elements[0];

	/* we know that in normal arrays the last element is the length - 1 */
	queue->tail = &queue->elements[length - 1];

	return queue;
}

int main() {
	Queue* queue = queue_create(magic_size);

	free(queue);
	queue = NULL;

	return 0;
}
