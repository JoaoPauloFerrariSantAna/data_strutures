#include <stdio.h>
#include <stdlib.h>

/* code based on teacher Douglas */

typedef int ListOpStat;

typedef struct Node {
	struct Node* head;
	struct Node* tail;
	int value;
} Node;

typedef struct {
	Node* next;
	Node* prev;
} List;

ListOpStat list_insert_at_head = 1;
ListOpStat list_mv_head = 2;
ListOpStat list_mv_tail = 4;
ListOpStat list_tail_as_head = 3;

List* list_create() {
	List* list = malloc(sizeof(List));
	list->next = NULL;
	list->prev = NULL;
	return list;
}

ListOpStat node_add_head(List* list, int value) {
	Node* new_head = malloc(sizeof(Node));

	/* here, we will be making an normal insertion */
	new_head->value = value;
	new_head->head = list->next;

	/* because we are creating an new new_head, we'll have to make */
	/* the tail point to NULL */
	/* (since the head is the first element ... */
	/* and the first element does not have something before it) */
	new_head->tail = NULL;

	/* we were configurating a new_head to be inserted in the list */
	/* but now, we need to check the list */
	/* and then also configure it */
	/* since the list may be actually empty at the first insertion */
	/* we'll also need to set "list->prev" to point to the "new_head" */

	/* (first insertion) */
	if(list->next == NULL) {
		/* here we are supposing that */
		/* the list starts empty */
		/* and if that is true then the first element is also the last one */
		/* sooo we will configure it */
		/* the tldr would be: set "->prev" and "->next" to new_head */
		list->next = new_head;
		list->prev = new_head;
		return list_insert_at_head;
	}

	/* (after first insertion) */
	/* in this case we are just moving the first head to after the new head */
	list->next->tail = new_head;
	/* and then setting the pointer to the new new_head in the list */
	list->next = new_head;
	return list_mv_head;
}

ListOpStat node_add_tail(List* list, int value) {
	Node* new_tail = malloc(sizeof(Node));
	new_tail->value = value;
	/* it will be the inverse of add_head */
	new_tail->tail = list->prev;
	new_tail->head = NULL;

	if(list->next == NULL) {
		/* will use the tail (supposing that "head" is empty) as the "head" */
		list->next = new_tail;
		return list_tail_as_head;
	}

	/* will move the current tail from whaterver it's initial value to "new_tail" */
	list->prev->head = new_tail;
	list->prev = new_tail;
	return list_mv_tail;
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

	node_add_head(list, 4);
	node_add_head(list, 5);
	node_add_head(list, 6);
	node_add_tail(list, 8);
	node_add_tail(list, 9);

	list_print(list);

	free(list);
	return 0;
}
