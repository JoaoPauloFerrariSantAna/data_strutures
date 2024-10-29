#include <stdio.h>
#include <stdlib.h>

/* now, how it is said on my language: */
/* "aqui é onde o filho chora e a mãe não vê" */
/* let's see if i can erase a head */

typedef int ListStat;

const ListStat list_empty = -5;
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

ListStat node_rm_recent_head(List* list) {
	Node* curr_head = list->next;
	Node* new_head;

	/* we'll want to check if the list is empty */
	/* 'cause then, it is impossible to erase what is not there */
	if(curr_head == NULL) {
		return list_empty;
	}

	new_head = curr_head->head;

	/* erases the pointer to the most recent value */
	free(curr_head);
	curr_head = NULL;

	/* now, we need to make "list" reference "new_head"'s head */
	list->next = new_head;

	return list_operation_succ;
}

ListStat node_rm_all_head(List* list) {
	Node* curr_head;
	if(list->next == NULL) {
		return list_empty;
	}

	curr_head = list->next;

	/* will delete all elements of the list */
	while(curr_head != NULL) {
		Node* new_head = curr_head->head;
		free(curr_head);

		/* since we need to remove all elements... */
		/* curr_head must point to the new_head */
		curr_head = new_head;
		list->next = new_head;
	}

	return list_operation_succ;
}

void list_print(List* list) {
	Node* nodes = list->next;

	while(nodes != NULL) {
		printf("%d\n", nodes->value);
		nodes = nodes->head;
	}
	printf("NULL\n");
	printf("----------------------\n");
}

int main() {
	List* list = list_create();

	node_add_head(list, 1);
	node_add_head(list, 2);
	node_add_head(list, 3);

	list_print(list);

	/* if(node_rm_recent_head(list) == list_empty) {
		printf("to remove the head, the list must not be empty.\n");
	} */

	if(node_rm_all_head(list) == list_empty) {
		printf("to remove the head, the list must not be empty.\n");
	}

	list_print(list);

	free(list);
	list = NULL;
	
	return 0;
}
