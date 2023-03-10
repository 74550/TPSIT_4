#include <stdio.h>
#include <stdlib.h>
#define LUNG 1024
#include <string.h>
#define NPERS 5

typedef char* Stringa;



typedef struct dati {
    Stringa cognome;
    Stringa nome;
    int data;
}Dati;

void scambio(Dati *x, Dati *y) {
    Dati t;

    t = *x;
    *x = *y;
    *y = t;
}


int main(){
    FILE *fp;
    fp=fopen("dati.csv", "r");

    Stringa riga;
    Dati *a;
    a=(Dati*)malloc(NPERS*sizeof(Dati));   //puntatore a struttura con locazione dinamica

    if(fp==NULL){
        printf("errore nell'apertura del file");
    } else {
        printf("sono dentro");

    int k=0;
    riga=(Stringa)malloc(LUNG*sizeof(char));

    while(fgets(riga, LUNG, fp)){
            riga = (Stringa) realloc(riga, (strlen(riga) + 1) * sizeof(char)); // + 1 per il terminatore
            (a+k)->cognome=strdup(strtok(riga,","));    //carattere divisore , 
            (a+k)->nome=strdup(strtok(NULL,","));
            (a+k)->data=atoi(strtok(NULL,","));
            riga=(Stringa)malloc(LUNG*sizeof(char)); // spazio di nuovo a 1024 per la nuova iterazione del ciclo

            k++;

        }
        for (int sup = NPERS-1; sup > 0; sup--) {
                for (int i = 0; i< sup; i++) {
                    if ((a+i)->data>(a+i+1)->data){
                        scambio(a+i,a+i+1);
                    }
                }
            } 


        for (int k = 0; k< NPERS; k++) {
            printf("\n%s, %s, %d",(a+k)->cognome, (a+k)->nome, (a+k)->data);
        }

            

    }

    fclose(fp);
    free(a);
    free(riga);
    return 1;

}