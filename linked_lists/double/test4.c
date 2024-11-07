#include <stdio.h>
#include <stdlib.h>

/* again, code was obtained teacher Douglas */ 
/* (i've tried to simplify a little bit my rationale) */
/* let's try to delete the head */

typedef struct Node {
	struct Node* head;
	struct Node* tail;
	int value;
} Node;

typedef struct {
	Node* next;
	Node* prev;
} List;

List* list_create() {
	List* list = malloc(sizeof(List));

	list->next = NULL;
	list->prev = NULL;

	return list;
}

void list_print(List* list) {
	Node* node = list->next;

	while(node != NULL) {
		printf("%d\n", node->value);
		node = node->head;
	}
}

void node_add_head(List* list, int value) {
	Node* new_head = malloc(sizeof(Node));

	new_head->value = value;

	/* 'cause it does not have something to point back */
	/* since it is at the start */
	new_head->tail = NULL;
	new_head->head = list->next;

	if(list->next == NULL) {
		/* will point to new head */
		list->next = new_head;
		/* will configure "->prev" to point to "new_head" */
		list->prev = new_head;
		return;
	}

	/* head turns into last to first element */
	list->next->tail = new_head;
	/* configures the pointer to be the the first */
	list->next = new_head;
}

void node_add_tail(List* list, int value) {
	Node* new_tail = malloc(sizeof(Node));

	new_tail->value = value;
	new_tail->tail = list->prev;

	/* 'cause it does not have something to point forwards */
	/* since it is in the end */
	new_tail->head = NULL;

	if(list->next == NULL) {
		/* will use the tail (supposing that "head" is empty) as the "head" */
		list->next = new_tail;
		return;
	}

	/* moves the current "tail" to be the second to last element */
	/* "->prev" is the "tail", "->prev->head" is what is before the "tail" */
	/* since it needs to be connected to something */
	list->prev->head = new_tail;

	/* makes "->prev" point to "new_tail" which is the actual */
	list->prev = new_tail;
}

int main() {
	List* list = list_create();

	node_add_head(list, 1);
	node_add_head(list, 2);
	node_add_tail(list, -1);
	list_print(list);

	return 0;
}
