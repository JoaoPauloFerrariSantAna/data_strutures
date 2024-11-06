#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* head;
    struct Node* tail;
    int value;
} Node;

typedef struct {
    struct Node* next;
    struct Node* prev;
} List;

List* list_create() {
    List* list = malloc(sizeof(List));

    list->next = NULL;
    list->prev = NULL;

    return list;
}

/* adding at head */
void node_add_head(List* list, int value) {
    Node* new_head = malloc(sizeof(Node));

    new_head->value = value;
    new_head->head = list->next;
	new_head->tail = NULL;
    list->next = new_head;
    list->prev = new_head->tail;
}

int main() {
    List* list = list_create();

    node_add_head(list, 1);
    node_add_head(list, 1);
    node_add_head(list, 2);
    node_add_head(list, 3);

    Node* aux = list->next;

    while(aux != NULL) {
        printf("%d\n", aux->value);
        aux = aux->head;
    }

    free(list);
    list = NULL;

    return 0;
}
