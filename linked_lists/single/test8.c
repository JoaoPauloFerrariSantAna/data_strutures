#include <stdio.h>
#include <stdlib.h>

/* again code obtained from teacher Douglas */
/* let's try to erase the tail, now */


typedef int ListStat;

const ListStat list_empty = -5;
const ListStat list_imposs_rm = -4;
const ListStat list_operation_succ = 0;

typedef struct Node {
	struct Node* head;
	int value;
} Node;

typedef struct {
	Node* next;
} List;

List* list_create() {
	List* list = malloc(sizeof(List));

	list->next = NULL;

	return list;
}

void node_add_head(List* list, int value) {
	Node* new_head = malloc(sizeof(Node));

	new_head->value = value;
	new_head->head = list->next;
	list->next = new_head;
}

ListStat node_add_tail(List* list, int value) {
	Node* new_tail = malloc(sizeof(Node));
	Node* aux;

	if(list->next == NULL) {
		return list_empty;
	}

	aux = list->next;

	new_tail->value = value;
	new_tail->head = NULL;

	/* mv end */
	while(aux->head != NULL) {
		aux = aux->head;
	}

	aux->head = new_tail;

	return list_operation_succ;
}

ListStat node_rm_tail(List* list) {
	Node* elements;

	if(list->next == NULL) {
		return list_empty;
	}

	elements = list->next;

	/* does list contains only one element */
	/* if it has, then it is impossible to continue */
	/* because then we can't get to the second to last element */
	if(elements->head == NULL) {
		return list_imposs_rm;
	}

	/* will go one ahead, so if i have "1, 2, 3" */
	/* and i'm at the start, then this will use the third element of the list */
	/* and see if there is something else (which does not) */
	/* "->head" goes to the next element, remember? */
	while(elements->head->head != NULL) {
		elements = elements->head;
	} /* second to last element here */

	/* free last element */
	free(elements->head);
	elements->head = NULL;

	return list_operation_succ;
}

void list_print(List* list) {
	Node* node = list->next;

	while(node != NULL) {
		printf("%d\n", node->value);
		node = node->head;
	}
}

int main() {
	List* list = list_create();
	int list_op_stat;

	node_add_head(list, 1);
	node_add_head(list, 2);
	node_add_head(list, 3);

	list_op_stat = node_rm_tail(list);
	list_op_stat = node_add_tail(list, 414);
	list_op_stat = node_add_tail(list, 413);

	if(list_op_stat == list_empty) {
		printf("Could not add element to the end of the list. List is empty\n");
	}

	if(list_op_stat == list_empty) {
		printf("Could not add element to the end of the list. List is empty\n");
	}

	if(list_op_stat == list_empty || list_op_stat == list_imposs_rm) {
		printf("Could not remove element in the end of list. List length err.\n");
	}

	list_print(list);

	return 0;
}
