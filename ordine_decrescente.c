#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  node {
    char nome[20];
    int punteggio;
    struct  node* next;
} Node;

void printList(Node* l) {
    printf("%s - %d - %p \n",l->nome,l->punteggio, l->next);
    if(l->next != NULL)
        printList(l->next);
}


int main() {
    Node* list = (Node*) malloc(sizeof(Node));
    list->next = NULL;

    for(int k=0;k<10;k++){
        printf("inserisci nome: ");
        gets(list->nome);
        printf("inserisci punteggio: ");
        scanf("%d",list->punteggio);
    }
    printList(list);

    return 0;
}
