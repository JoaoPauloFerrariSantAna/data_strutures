#include <stdio.h>
#include <stdlib.h>

typedef int ListOpStat;

typedef struct Node {
	struct Node* head;
	int value;
	struct Node* tail;
} Node;

typedef struct {
	struct Node* next;
	struct Node* prev;
} List;

ListOpStat list_head_empty = -5;
ListOpStat list_head_nempty = 1;

List* list_create() {
	List* list = malloc(sizeof(List));

	list->next = NULL;
	list->prev = NULL;

	return list;
}

void node_add_head(List* list, int value) {
    Node* new_head = malloc(sizeof(Node));

    new_head->value = value;
    new_head->head = list->next;

	/* remember: the head is always the first item */
	/* so, we need to set head's tail to NULL (empty) */
	new_head->tail = NULL;
	
	list->prev = new_head;
	/* this will also insert at tail */
	/* it's ok though */
	/* because the "tail" of the "head" is also "head" of "list->prev" */
	new_head->head = list->next;
	list->next = new_head;

	/* my is spinning :v */
}


void node_add_tail(List* list, int value) {
	Node* new_tail = malloc(sizeof(Node));

	new_tail->value = value;

	/* because the head of the "new_tail" is pointing to nothing, because it is in the end */
	new_tail->head = NULL;

	new_tail->tail = list->prev;
	list->prev = new_tail;
}

void list_print_head(Node* heads) {
	while(heads != NULL) {
		printf("%d\n", heads->value);
		heads = heads->head;
	}

	printf("<EOH>\n");
}

void list_print_tail(Node* tails) {
	while(tails != NULL) {
		printf("%d\n", tails->value);
		tails = tails->tail;
	}

	printf("<EOT>\n");
}

void list_print(List* list) {
	list_print_head(list->next);
	list_print_tail(list->prev);
}

int main() {
	List* list = list_create();

	if(list == NULL) {
		exit(1);
	}

	node_add_head(list, 1);

	node_add_tail(list, 413);
	node_add_tail(list, 612);

	list_print(list);

	free(list);
	list = NULL;

	return 0;
}
