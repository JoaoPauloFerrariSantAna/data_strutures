#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
	struct Node* head;
	int data;
} Node;

typedef struct {
	Node* next;
} List;

List* list_create() {
	List* list = malloc(sizeof(List));

	list->next = NULL;

	return list;
}

void list_print(List* list) {
	Node* aux = list->next;

	while(aux != NULL) {
		printf("%d\n", aux->data);
		aux = aux->head;
	}
}

bool list_search(List* list, int to_search) {
	bool founded = false;
	Node* aux = list->next;

	while(aux != NULL) {
		if(aux->data == to_search) {
			founded = true;
		}

		aux = aux->head;
	}

	return founded;
}

void node_add_head(List* list, int data) {
	Node* new_head = malloc(sizeof(Node));

	new_head->data = data;
	new_head->head = list->next;
	list->next = new_head;
}

void node_add_tail(List* list, int data) {
	Node* new_tail = malloc(sizeof(Node));

	new_tail->data = data;
	new_tail->head = NULL;

	if(list->next == NULL) {
		/* set new tail as the head */
		new_tail->head = list->next;
		list->next = new_tail;
		return;
	}
	
	while(list->next->head != NULL) { list->next = list->next->head; }
	
	list->next->head = new_tail;
}

int main() {
	int number_search = 3;
	List* list = list_create();

	node_add_head(list, 1);
	node_add_tail(list, 2);

	if(list_search(list, number_search)) {
		printf("number \"%d\" was found.\n", number_search);
	} else {
		printf("number \"%d\" was not found.\n", number_search);
	}

	free(list);
	list = NULL;
	return 0;
}
