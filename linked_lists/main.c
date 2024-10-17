#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* there's a mistake somewhere... */

typedef struct Node {
    struct Node * start;
    struct Node * end;
    int value;
} Node;

Node* node_create() {
    Node *node = malloc(sizeof(Node));

    node->start = NULL;
    node->end = NULL;

    return node;
}

void node_add_start(Node *node, int value) {
    Node *begin = malloc(sizeof(Node));

    /* suponde que "*node" tenha sido iniciado... */
    /* begin->start = node->start onde node->start é NULL */
    begin->value = value;
    begin->start = node->start;
    /* node->start olha agora para begin->start */
    node->start = begin;
}

void node_remove_start(Node *node, int erase_val) {
    while(node != NULL) {
        if(node->value == erase_val) {
            /* eu preciso ou "apagar" esse elemento ou "pular" ele */
            node->value = 0;
        }
        node = node->start;
    }
}

void node_add_end(Node *node, int value) {
    Node *end = malloc(sizeof(Node));

    end = node;

    while(end != NULL) {
        /* se estivermos no começo da lista... */
        if(end->start == NULL) {
            end->value = value;
            end->end = node->start;
            node->value = end->value;
        }
        end = end->start;
    }
}

void node_remove_end(Node *node/*, int erase_val */) {
    Node *aux = malloc(sizeof(Node));

    aux = node;

    while(aux != NULL) {
        puts("banana");
        aux = aux->end;
    }
}

void print_start(Node *node) {
    while(node != NULL) {
        printf("%d\n", node->value);
        node = node->start;
    }
    puts("nill");
}

void print_end(Node *node) {
    while(node != NULL) {
        printf("%d\n", node->value);
        node = node->end;
    }
    puts("nill");
}

int main() {
    Node *node = node_create();

    // int elemento_apagar = 413;

    // node_add_start(node, 4);
    // node_add_start(node, 2);
    // node_add_start(node, elemento_apagar);

    node_add_end(node, 1);
    node_add_end(node, 5);
    node_add_end(node, 6);
    node_add_end(node, 7);

    // print_start(node);
    // print_end(node);

    // node_remove_end(node);

    free(node);
    node = NULL;

    return 0;
}