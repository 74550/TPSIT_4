#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct  node {
    int  valore;
    struct  node* next;
} Node;

void printList(Node* l) {
    printf("%d - %p \n",l->valore, l->next);
    if(l->next != NULL)
        printList(l->next);
}

int nNodes(Node* l) {
    if(l != NULL)
        return nNodes(l->next) + 1;
    return 0;
}

void insertHead(Node** head, int new_valore) {
    Node* new_testa = (Node*) malloc(sizeof(Node));
    new_testa->valore = new_valore;
    new_testa->next = *head;
    *head = new_testa;
}

void da_lista_ad_array(Node *l){
    Node array[MAX];
    for(int k=0;k<MAX;k++){
        l->valore=array[k];
    }
}

int main() {
    Node* head = (Node*) malloc(sizeof(Node));
    head->next = (Node*) malloc(sizeof(Node));
    head->valore = 3;
    head->next->next = NULL;
    head->next->valore = 8;
    
    printList(head);
    printf("\n");

    insertHead(&head, 5);
    printList(head);

    return 0;
}
