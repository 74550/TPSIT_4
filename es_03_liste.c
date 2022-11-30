/*crea  una  lista e la  stampa*/
#include  <stdio.h>
#include  <stdlib.h>

typedef struct  node
{
    int  valore;
    struct  node* next;
}Node;

void printList(Node* l) { //passo la testa
    printf("%d - %p \n",l->valore, l->next);  //stampa il valore del nodo corrente e l'indirizzo del successivo
    if(l->next != NULL)
        printList(l->next);
}

int nNodes(Node* l) {  //passiamo la testa
    if(l != NULL)
        return nNodes(l->next) + 1;  //incremento il numero di nodi dal successivo col +1, perchè il nodo esiste
    return 0; //quando non ci son più nodi
}

int  main()
{
    int n;
    Node* lista;
    Node* l;
    lista=NULL;

    do
    {
        printf("Inserisci  un  naturale o  -1 per  terminare: ");
        scanf("%d",&n);
        if (n>=0)
        {
            if (lista==NULL) /*  prima iterazione  */
            {
                lista = (Node*)  malloc(sizeof(Node));
                l = lista;
            }
            else /*  iterazioni successive  */
            {
                l->next = (Node*)  malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n>=0);   //lista avrà il valore della testa
                      //l scorre la lista
                      //l contiene sempre l'ultimo valore al momento
                      //lista contiene l, non il contrario
    printList(lista);
    printf("nodi: %d\n", nNodes(lista));

    return  0;
}
