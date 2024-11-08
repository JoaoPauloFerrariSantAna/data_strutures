#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QueueData;
typedef int QueueStat;

QueueStat queue_empty = -5;

/* now let's see the rear */

typedef struct QueueElement {
	struct QueueElement* tail;
	QueueData value;
} QueueElement;

/* now let's create the actual queue */
typedef struct {
	QueueElement* prev;
	int length;
} Queue;

bool is_link_empty(QueueElement* link) {
	return (link == NULL);
}

/* let's create a queue */
Queue* queue_create() {
	Queue* queue = malloc(sizeof(Queue));

	queue->prev = NULL;
	queue->length = 0;

	return queue;
}

void queue_print(Queue* q) {
	QueueElement* elements = q->prev;

	printf("Queue has length: %d\n", q->length);

	while(is_link_empty(elements)) {
		printf("%d\n", elements->value);

		/* this is saying "go back" */
		elements = elements->tail;
	}

}

/* we insert a value in a queue at the end, soooo... */
/* we must make a insertion like in a tail of a singly linked list */
void enqueue(Queue* q, QueueData value) {
	/* we must create a "QueueElement" */
	QueueElement* qelement = malloc(sizeof(QueueElement));
	QueueElement* aux = NULL;

	qelement->value = value;
	qelement->tail = NULL;

	/* if there's nothing at the end */ 
	/* then we must set "->prev" to track qelement as the first element */
	if(is_link_empty(q->prev)) {
		q->prev = qelement;
		return;
	}

	aux = q->prev;

	/* first, we'll go to the end of the queue */
	while(!is_link_empty(aux->tail)) { aux = aux->tail; } 

	/* from here on out we are at the last element */
	aux->tail = qelement;

	q->length++;
}

/* now let's remove a element of the queue */
void dequeue(Queue* q) {
	/* so we must check if one element */
	/* after the current is the tail */
	QueueElement* aux = q->prev;

	if(is_link_empty(aux)) {
		/* queue is empty */
		return;
	}

	/* so.. while the element after the current one */
	/* is not empty, continue to advance on the queue */
	while(!is_link_empty(aux->tail->tail)) { aux = aux->tail; }

	/* removing the front */
	free(aux->tail);
	aux->tail = NULL;

	/* updating queue length */
	q->length--;
}

QueueData peek(Queue* q) {
	QueueElement* aux;

	if(is_link_empty(q->prev)) {
		/* Queue is empty */
		return 0;
	}

	aux = q->prev;

	/* just move it to the end and then store it in a variable */
	while(!is_link_empty(aux->tail)) { aux = aux->tail; }

	return aux->value;
}

QueueData rear(Queue* q) {
	QueueElement* aux;

	if(q->prev == NULL) {
		return 0;
	}

	aux = q->prev;

	return aux->value;
}

int main() {
	Queue* queue = queue_create();
	
	free(queue);
	queue = NULL;

	return 0;
}
