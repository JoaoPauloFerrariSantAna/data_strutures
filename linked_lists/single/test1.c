#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* there's a mistake somewhere... */

typedef struct Node {
    struct Node * start;
    struct Node * end;
    int svalue;
    int evalue;
} Node;

Node* node_add_end(Node* node, int value) {
    Node *end = malloc(sizeof(Node));

    end->start = node;
    end->end = node;
    end->evalue = value;

    return end;
}

Node* node_add_start(Node *node, int value) {
    Node *begin = malloc(sizeof(Node));

    begin->start = node;
    begin->end = node;
    begin->svalue = value;

    return begin;
}

void print_end(Node* node) {
    puts("----------END----------");
    while(node != NULL) {
        if(node->end == NULL) {
            break;
        }

        if(node->evalue == 0) {
            node = node->end;
            continue;
        }

        printf("%d\n", node->evalue);
        node = node->end;
    }
    puts("----------END----------");
}

void print_start(Node* node) {
    puts("----------START----------");
    while(node != NULL) {
        if(node->start == NULL) {
            break;
        }

        printf("%d", node->svalue);
        node = node->start;
    }
    puts("\n----------START----------\n");
}

void print_all(Node* node) {
    puts("----------ALL----------");
    while(node != NULL) {
        if(node == NULL) {
            break;
        }

        if(node->evalue == 0) {
            node = node->end;
            continue;
        }

        printf("%d\n", node->evalue);
        printf("%d\n", node->svalue);
        node = node->start;
        node = node->end;
    }
    puts("\n----------ALL----------\n");
}

int main() {
    Node *node = malloc(sizeof(Node));

    node->start = NULL;
    node->end = NULL;

    node = node_add_end(node, 45);
    node = node_add_end(node, 77);
    node = node_add_start(node, 612);
    node = node_add_start(node, 888);

    /* print_end(node); */

    print_all(node);

    free(node);

    return 0;
}