#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* head;
    int value;
    struct Node* tail;
} Node;

typedef struct {
    Node* next;
    Node* prev;
} List;

List* list_create() {
    List* list = malloc(sizeof(List));

    list->next = NULL;
    list->prev = NULL;

    return list;
}

void list_print(List* list) {
    Node* aux = list->next;

    while(aux != NULL) {
        printf("%d\n", aux->value);
        aux = aux->head;
    }
}

void list_print_rev(List* list) {
    Node* aux = list->prev;

    while(aux != NULL) {
        printf("%d\n", aux->value);
        aux = aux->tail;
    }
}

void node_add_head(List* list, int value) {
    Node* newh = malloc(sizeof(Node));

    /* will make the head pointer track the next the first node */
    newh->head = list->next;

    /* 'cause there is nothing in the front */
    newh->tail = NULL;

    newh->value = value;

    /* first insertion */
    if(list->next == NULL) {
        /* will set to track newh at every point of the list */
        list->next = newh;
        list->prev = newh;
        return;
    } /* now it is the normal part */

    /* will make the second node be the tail of what is after it */
    list->next->tail = newh;
    
    /* will make the second node be the head of the node after it */
    list->next = newh;
}

void node_rm_head(List* list) {
    Node* rmh = list->next;

    list->next = rmh->head;

    list->next->tail = NULL;

    free(rmh);
}

void node_rm_tail(List* list) {
    Node* rmt = list->prev;
    
    list->prev = rmt->tail;
    list->prev->head = NULL;

    free(rmt);
}

void node_add_tail(List* list, int value) {
    Node* newt = malloc(sizeof(Node));

    /* 'cause there is nothing in the back */
    newt->head = NULL;

    /* it is ok to do it this way 'cause then if the list is empty, we'll */
    /* add the tail to the list so that the list is not empty */
    /* will make the tail pointer track the last node */
    newt->tail = list->prev;

    newt->value = value;

    if(list->next == NULL) {
        list->prev = newt;
        return;
    }

    /* will set the second to last node be the head of what is before */
    list->prev->head = newt;
    
    /* will set the second to last node to be prev's head */
    list->prev = newt;
}

int main() {
    List* list = list_create();

    if(list == NULL) {
        printf("Could not create list.\n");
        return 1;
    }

    node_add_head(list, 1);
    node_add_head(list, 2);
    node_add_tail(list, 3);
    node_add_tail(list, 4);

    // node_rm_tail(list);
    // node_rm_head(list);

    // list_print(list);
    list_print_rev(list);

    free(list);
    list = NULL;
    
    return 0;
}