#include <stdio.h>
#include <stdlib.h>

typedef int NodeStatus;

typedef struct Node {
	struct Node* head;
	int value;
} Node;

NodeStatus node_err = 0;
NodeStatus node_ok = 1;

Node *node_create() {
	Node *node = malloc(sizeof(Node));
	node->head = NULL;
	return node;
}

void node_add_head(Node *node, int value) {
	Node* new_head = malloc(sizeof(Node));
	new_head->value = value;
	new_head->head = node->head;
	node->head = new_head;
}

NodeStatus node_rm_head(Node* node) {
	if(node->head == NULL) {
		return node_err;
	}

	Node* elements = node;
	node = node->head; /* moves to next element */
	free(elements);



	return node_ok;
}

void node_print(Node* node) {
	while(node != NULL) {
		printf("%d\n", node->value);
		node = node->head;
	}
}

int main() {
	Node *node = node_create();

	node_add_head(node, 1);
	node_add_head(node, 2);
	node_add_head(node, 3);

	if(node_rm_head(node) == node_err) {
		printf("list is empty\n");
		return 1;
	}

	node_print(node);
	return 0;
}
