#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char* name;
    struct node* next;
} Node;

void dealloca(Node *list){
    Node *temp;
    while(list!=NULL){
        temp=list;
        list=list->next;
        free(temp);
    }
}

int main() {
    Node* lista = (Node*) malloc(sizeof(Node));
}
