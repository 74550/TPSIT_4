#include <stdio.h>
#include <stdlib.h>

typedef struct  node {
    int  value;
    struct  node* next;
} Node;

void insHead(Node** head, Node* el) {
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

void InserisciCoda(Node *pl) {
    Node* t;

    /* caso lista inizialmente vuota */
    if(pl==NULL) {
        Node*pl=(Node*)malloc(sizeof(Node));
        pl->value=9;
        pl->next=NULL;
        return;
    }

    /* caso lista con almeno un elemento */
    //*t=*pl;

    /* vado avanti fino alla fine della lista */
    /*while(t->next!=NULL)
        t=t->next;

    /* qui t punta all'ultima struttura della lista: ne
    creo una nuova e sposto il puntatore in avanti */
    /*t->next=(Node*)malloc(sizeof(Node));
    t=t->next;

    /* metto i valori nell'ultima struttura */
   /* t->value=e;
    t->next=NULL;*/
}


void stampa(Node *l){

    int k=0;
    //printf("STAMPA CON PROC: \n");
    while (l!=NULL && k<5)                                  //puntatore alla lista diversa da NULL
    {
        printf("%d \n",l->value);
        l=l->next;                                          //assegna ad l il campo successivo, all'ultima iterazione assegna il campo NULL ed esce dal ciclo
        k++;
    }
}

int main() {
    int n;
    Node* lista;                                            //tipo a puntatore a node
    lista = NULL;

    do
    {
        printf("Inserisci il valore del viodeogioco o -1 per  terminare\n");
        scanf("%d",&n);

        if (n!=-1){
           /* Node *elem;
            elem = (Node*)malloc(sizeof(Node));
            elem->value=n;
            elem->next=NULL;*/

            InserisciCoda(&lista);
        }

    } while (n>=0);

    Node *l = lista;
    stampa(lista);

    return  0;
}


