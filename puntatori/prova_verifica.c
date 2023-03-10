#include <stdio.h>
#include <stdlib.h>
#define LUNG 1024
#include <string.h>
#define NPERS 5

typedef char* Stringa;

typedef struct dati{
    Stringa nome;
    Stringa cognome;
    int data;
};

int main(){
    Dati *a;
    a=(Dati*)malloc(NPERS*sizeof(Dati));
    FILE *fp;
    fp=fopen("dati.csv","r");
    Stringa riga;
    riga=(Stringa)malloc(LUNG*sizeof(char));
    int k=0;
    while(fgets(riga, LUNG, fp)){
        (a+k)->nome=strdup(strtok(riga, ","));
        (a+k)->cognome=strdup(strtok(NULL, ","));
        (a+k)->data=atoi(strtok(NULL, ","));
        k++;
    }
    free(a);
    free(riga);

}