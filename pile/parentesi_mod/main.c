#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data;
    struct node* next;
} node;

node* head = NULL;

void push(char c) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = c;
    new_node->next = head;
    head = new_node;
}

char pop() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return '\0';
    }
    node* temp = head;
    head = head->next;
    char c = temp->data;
    free(temp);
    return c;
}

int check_balanced(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(str[i]);
        } else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            char c = pop();
            if (str[i] == ')' && c != '(') {
                return 0;
            } else if (str[i] == ']' && c != '[') {
                return 0;
            } else if (str[i] == '}' && c != '{') {
                return 0;
            }
        }
    }
    if (head == NULL) {
        return 1;
    }
    return 0;
}

int main() {
    char str[MAX_SIZE];
    printf("Inserisci la stringa di parentesi: ");
    scanf("%s", str);
    if (check_balanced(str)) {
        printf("Le parentesi son correttamente chiuse\n");
    } else {
        printf("Le parentesi non son correttamente chiuse\n");
    }
    return 0;
}

