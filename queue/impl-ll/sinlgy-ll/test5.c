#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QueueData;
typedef int QueueStat;

QueueStat queue_empty = -5;

/* now let's see the rear */

typedef struct QueueElement {
	struct QueueElement* front;
	QueueData value;
} QueueElement;

/* now let's create the actual queue */
typedef struct {
	int length;
	QueueElement* rear;
} Queue;

bool is_link_empty(QueueElement* link) {
	return (link == NULL);
}

/* let's create a queue */
Queue* queue_create() {
	Queue* queue = malloc(sizeof(Queue));

	queue->rear = NULL;
	queue->length = 0;

	return queue;
}

void queue_print(Queue* q) {
	QueueElement* elements = q->rear;

	printf("Queue has length: %d\n", q->length);

	while(!is_link_empty(elements)) {
		printf("%d\n", elements->value);
		/* this is saying "go back" */
		elements = elements->front;
	}

}

/* we insert a value in a queue at the end, soooo... */
/* we must make a insertion like in a front of a singly linked list */
void enqueue(Queue* q, QueueData value) {
	/* we must create a "QueueElement" */
	QueueElement* qelement = malloc(sizeof(QueueElement));
	QueueElement* aux = NULL;

	qelement->value = value;
	qelement->front = NULL;

	q->length++;

	/* if there's nothing at the end */ 
	/* then we must set "->rear" to track qelement as the first element */
	if(is_link_empty(q->rear)) {
		q->rear = qelement;
		return;
	}

	aux = q->rear;

	/* first, we'll go to the end of the queue */
	while(!is_link_empty(aux->front)) { aux = aux->front; } 

	/* from here on out we are at the last element */
	aux->front = qelement;
}

/* now let's remove a element of the queue */
void dequeue(Queue* q) {
	QueueElement* aux = NULL;
	QueueElement* elements = NULL;

	/* can't remove 'nuff with queue empty  */
	if(q->rear == NULL) {
		printf("Queue is empty, already.\n");
		return;
	}

	/* current item in queue */
	aux = q->rear;
	/* next item after aux */
	elements = aux->front;

	/* removing pointer to queue item */
	free(aux);

	q->rear = elements;
}

QueueData peek(Queue* q) {
	QueueElement* aux;

	/* Queue is empty */
	if(is_link_empty(q->rear)) {
		return 0;
	}

	aux = q->rear;

	/* just move it to the end and then return it */
	while(!is_link_empty(aux->front)) { aux = aux->front; }

	return aux->value;
}

QueueData rear(Queue* q) {
	QueueElement* aux;

	if(q == NULL) {
		return 0;
	}

	aux = q->rear;

	return aux->value;
}

int main() {
	Queue* queue = queue_create();

	enqueue(queue, 1);
	enqueue(queue, 2);

	dequeue(queue);

	/* what i would just to have namespaces in C */
	queue_print(queue);

	free(queue);
	queue = NULL;

	return 0;
}
