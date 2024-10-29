#include <stdio.h>
#include <stdlib.h>

/* WARNING: THIS CODE IS NOT MINE */
/* it is pretty much the teacher's code with my rationale in between */

/* so... i've been studying for a while */
/* more on the commit, but suffice to say that... */
/* i've been doing stuff wrong */
/* i will try to comment where it is needed (the whole code) */

/* so... we'll start by creating a "struct Node" */
/* nothing new here... */
typedef struct Node {
	/* we'll still have a head here */
	struct Node* head;
	/* and a value */
	int value;
} Node;

/* but now, we will need to have a "struct" typefied to "List" */
typedef struct {
	/* "struct" will just have a pointer to "Node" */
	Node* next;
} List;

/* we'll want to create a list, so... */
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

/* now let's add a head to the list, right? */
void node_add_head(List* list, int value) {
	/* now here is the same */
	Node* new_head = malloc(sizeof(Node));

	new_head->value = value;

	/* list->next points to a "Node" */
	/* so the pointer in "new_head->head" must be pointing to the "next" element*/
	new_head->head = list->next;

	/* and we must update the "next" pointer to the new "head" */
	list->next = new_head;
}

void node_print(List* list) {
	Node* aux = list->next;

	/* so, if it shows a zero at the beginning, it has some error */
	while(aux != NULL) {
		printf("%d\n", aux->value);
		aux = aux->head;
	}
}

int main() {
	List* list = list_create();

	node_add_head(list, 1);
	node_add_head(list, 2);
	node_add_head(list, 3);
	node_print(list);

	free(list);
	list = NULL;

	return 0;
}
