#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool is_link_empty(Node* link) {
	return (link == NULL);
}

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
	Node* aux = NULL;
	if(is_link_empty(list->next)) {
		return list_empty;
	}
	aux = list->next;
	new_tail->value = value;
	new_tail->head = NULL;
	/* mv end */
	while(!is_link_empty(aux->head)) {
		aux = aux->head;
	}
	aux->head = new_tail;
	return list_operation_succ;
}

ListStat node_rm_tail(List* list) {
	Node* elements = NULL;
	if(is_link_empty(list->next)) {
		return list_empty;
	}
	elements = list->next;
	/* does list contains only one element */
	/* if it has, then it is impossible to continue */
	/* because then we can't get to the second to last element */
	if(is_link_empty(elements->head)) {
		return list_imposs_rm;
	}
	/* will go one ahead, so if i have "1, 2, 3" */
	/* and i'm at the start, then this will use the third element of the list */
	/* and see if there is something else (which does not) */
	/* "->head" goes to the next element, remember? */
	while(!is_link_empty(elements->head->head)) {
		elements = elements->head;
	} /* second to last element here */
	/* free last element */
	free(elements->head);
	elements->head = NULL;
	return list_operation_succ;
}

void list_print(List* list) {
	Node* node = list->next;
	while(!is_link_empty(node)) {
		printf("%d\n", node->value);
		node = node->head;
	}
}

int main() {
	List* list = list_create();
	list_print(list);
	return 0;
}
