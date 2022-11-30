#include <stdio.h>
#include <stdlib.h>

typedef struct  node {
    int  value;
    struct  node* next;
} Node;

void printList(Node* l) {
    printf("%d - %p \n",l->value, l->next);
    if(l->next != NULL)
        printList(l->next);
}

void freeList(Node* l) {
    if(l->next != NULL)
        freeList(l->next);
    free(l);
}

void insNode(Node** head, Node* el) {
    Node* prev = NULL;
    Node* curr = *head;

    while(curr != NULL) {
        if(el->value <= curr->value)
            break;
        prev = curr;
        curr = curr->next;
    }

    if(prev == NULL)
        *head = el;
    else
        prev->next = el;

    el->next =curr;
}

int main() {
    Node* head = (Node*) malloc(sizeof(Node));
    head->next = (Node*) malloc(sizeof(Node));
    head->value = 3;
    head->next->next = NULL;
    head->next->value = 8;

    printList(head);
    printf("\n");

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->value = 1;

    insNode(&head, newNode);
    printList(head);

    return 0;
}
