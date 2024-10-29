#include <stdio.h>
#include <stdlib.h>

/* código cópiado parcialmente do professor Douglas Rodrigues, faculdade UNIMAR 2024*/
/* (inserir na tail é meio estranho) */

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

NodeStatus node_add_tail(Node *node, int value) {
	Node *new_tail = node_create();

	new_tail->value = value;

	/* lista está vazia */
	if(node->head == NULL) {
		return node_err;
	}

	/* vai mover especifícamente a "head" ao fim */
	while(node->head != NULL) {
		/* vai passar por cada "node" */
		node = node->head;
	} /* DESTE PONTO EM DIANTE: "node" ESTÁ NO FIM */

	/* já que a head aqui é vazia (NULL) */
	/* e "new_tail" tem sua "head" como NULL  */
	/* posso fazer com que a "head" do "node" olhe para "new_tail" */
	/* e, então adicionar um item no fim do node */
	node->head = new_tail;

	return node_ok;
}

void node_print(Node* node) {
	while(node != NULL) {
		printf("%d\n", node->value);
		node = node->head;
	}
	puts("NILL");
}

int main() {
	Node *node = node_create();

	node_add_head(node, 1);
	node_add_head(node, 2);

	if(node_add_tail(node, 6) == node_err) {
		puts("Não posso adicionar no fim da lista com ela vazia");
	}

	if(node_add_tail(node, 7) == node_err) {
		puts("Não posso adicionar no fim da lista com ela vazia");
	}

	node_print(node);

	return 0;
}
