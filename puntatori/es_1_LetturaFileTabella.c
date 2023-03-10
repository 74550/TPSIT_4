#include <stdio.h>
#include <stdlib.h>
#define LUNG 1024
#include <string.h>
#define NGIOCHI 16600

typedef char* Stringa;

typedef struct dati {
    int rank;
    Stringa nome;
    Stringa piattaforma;
    int anno;
    Stringa genere;
    Stringa produttore;
    float venditeUsa;
    float venditeEu;
    float venditeJp;
    float altreVendite;
    float venditeGlobali;
}Dati;

int main(){
    FILE *fp;
    fp=fopen("vgsales.csv", "r");

    char* riga;
    Dati *a;
    a=(Dati*)malloc(16600*sizeof(Dati));
    
   



    if(fp==NULL){
        printf("errore nell'apertura del file");
        return 0;
    } else {
    printf("sono dentro");

    int k=0;
    riga=(char *)malloc(1024*sizeof(char ));

    while(fgets(riga, LUNG, fp)){
            riga = (char*) realloc(riga, (strlen(riga) + 1) * sizeof(char)); // + 1 per il terminatore
            (a+k)->rank=atoi(strtok(riga,","));
            (a+k)->nome=strtok(NULL,",");
            (a+k)->piattaforma=strtok(NULL,",");
            (a+k)->anno=atoi(strtok(NULL,","));
            (a+k)->genere=strtok(NULL,",");
            (a+k)->produttore=strtok(NULL,",");
            (a+k)->venditeUsa=atof(strtok(NULL,","));
            (a+k)->venditeEu=atof(strtok(NULL,","));
            (a+k)->venditeJp=atof(strtok(NULL,","));
            (a+k)->altreVendite=atof(strtok(NULL,","));
            (a+k)->venditeGlobali=atof(strtok(NULL,","));
            riga=(char *)malloc(1024*sizeof(char )); // spazio di nuovo a 1024 per la nuova iterazione del ciclo



           printf("\n%d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f",(a+k)->rank, (a+k)->nome, (a+k)->piattaforma, (a+k)->anno, 
                    (a+k)->genere, (a+k)->produttore, (a+k)->venditeUsa, (a+k)->venditeEu, (a+k)->venditeJp, (a+k)->altreVendite, 
                    (a+k)->venditeGlobali);
                    

            k++;

    }
    }

    fclose(fp);
    free(a);
    free(riga);
    return 1;
}
