#include <stdio.h>
#include <stdlib.h>

typedef int ListStat;

const ListStat list_empty = -5;
const ListStat list_nempty = 0;

/* now let's to add at tail */
typedef struct Node {
	struct Node* head;
	int value;
} Node;


typedef struct {
	/* "struct" will just have a pointer to "Node" */
	Node* next;
} List;

/* i'll begin to use "aux" with more frequency */

List* list_create() {
	List* list = malloc(sizeof(List));

	/* it is needed to set "next" node to NULL */
	list->next = NULL;

	/* so: this needs to happen because when i was setting  */
	/* "node->head" to NULL, i was actually setting the first node element to NULL */
	/* it was ok to inserting at head and tail, but to delete the head */
	/* it was not going to work 'cause you can't "free(NULL)" */
	/* the difference between this and those others test is that: */
	/* i'm not setting node element to NULL, i'm setting a node NULL */
	/* AND THEN setting it "head" pointer and "int value" */
	/* (i hope that my logic is correct here) */
	/* more on the commit message, by the way! */
	return list;
}

void node_add_head(List* list, int value) {
	Node* new_head = malloc(sizeof(Node));

	new_head->value = value;
	new_head->head = list->next;
	list->next = new_head;
}

ListStat node_add_tail(List* list, int value) { 
	Node* aux;
	Node* new_tail = malloc(sizeof(Node));

	new_tail->value = value;

	/* we want to set the head to NULL here 'cause */
	/* at the end of the list we do not have nothing  */
	/* but we want a NEW head */
	new_tail->head = NULL;

	/* we want to check if the list is empty */

	/* if it empty we can or return an err or make the "next" point to "new_tail" */
	/* i'll return an status */

	/* we can check if the list is NULL by just "list->next" */
	/* since we start the list with NULL (list_create) */
	if(list->next == NULL) {
		return list_empty;
	}

	aux = list->next;

	/* mv to end */
	/* "aux->head != NULL" checks if the pointer to the next head does not exits */
	/* "aux != NULL" checks if there is still nodes left to go to */
	while(aux->head != NULL) {
		aux = aux->head;
	}

	aux->head = new_tail;

	return list_nempty;
}

void list_print(List* list) {
	Node* aux = list->next;

	while(aux != NULL) {
		printf("%d\n", aux->value);
		aux = aux->head;
	}
}

int main() {
	List* list = list_create();

	node_add_head(list, 1);
	node_add_head(list, 2);

	if(node_add_tail(list, 413) == list_empty) {
		printf("List is empty, add something first.\n");
	}

	list_print(list);

	free(list);
	list = NULL;

	return 0;
}
