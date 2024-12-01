#include <stdio.h>
#include <stdlib.h>

typedef int QueueData;
typedef int QueueElement;

typedef struct Element {
	struct Element* front;
	QueueElement data;
} Element;

typedef struct {
	Element* rear;
	int length;
} Queue;

Queue* queue_init() {
	Queue* queue = malloc(sizeof(Queue));

	queue->rear = NULL;

	return queue;
}

void queue_print(Queue* queue) {
	Element* aux = queue->rear;

	while(aux != NULL) {
		printf("%d\n", aux->data);
		aux = aux->front;
	}
}

void enqueue(Queue* queue, int data) {
	Element* aux = NULL; 
	Element* new_rear = malloc(sizeof(Element));

	queue->length++;
	new_rear->data = data;
	new_rear->front = NULL;

	if(queue->rear == NULL) {
		queue->rear = new_rear; /* will work as FRONT */
		return;
	}

	aux = queue->rear;
	while(aux->front != NULL) { aux = aux->front; }
	aux->front = new_rear;
}

void dequeue(Queue* queue) {
	Element* aux = queue->rear;

	if(aux == NULL) {
		printf("Queue is empty.\n");
		return;
	}

	queue->length--;
	queue->rear = aux->front;
	free(aux);
	aux = NULL;
}

int main() {
	Queue* queue = queue_init();

	if(queue == NULL) {
		printf("Could not create queue...");
		return 1;
	}

	enqueue(queue, 1);
	enqueue(queue, 2);
	enqueue(queue, 3);
	dequeue(queue);
	queue_print(queue);

	free(queue);
	queue = NULL;

	return 0;
}
