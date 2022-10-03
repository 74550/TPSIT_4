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

    char riga[LUNG];
    Dati giochi[NGIOCHI];
    Dati* puntatore=giochi;



    if(fp==NULL){
        printf("errore nell'apertura del file");
        return 0;
    } else {
    printf("sono dentro");

    int k=0;

    while(fgets(riga, LUNG, fp)){
            (puntatore+k)->rank=atoi(strtok(riga,","));
            (puntatore+k)->nome=strtok(NULL,",");
            (puntatore+k)->piattaforma=strtok(NULL,",");
            (puntatore+k)->anno=atoi(strtok(NULL,","));
            (puntatore+k)->genere=strtok(NULL,",");
            (puntatore+k)->produttore=strtok(NULL,",");
            (puntatore+k)->venditeUsa=atof(strtok(NULL,","));
            (puntatore+k)->venditeEu=atof(strtok(NULL,","));
            (puntatore+k)->venditeJp=atof(strtok(NULL,","));
            (puntatore+k)->altreVendite=atof(strtok(NULL,","));
            (puntatore+k)->venditeGlobali=atof(strtok(NULL,","));




           printf("\n%d, %s, %s, %d, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f",(puntatore+k)->rank, (puntatore+k)->nome, (puntatore+k)->piattaforma, (puntatore+k)->anno, (puntatore+k)->genere,
                    (puntatore+k)->produttore, (puntatore+k)->venditeUsa, (puntatore+k)->venditeEu, (puntatore+k)->venditeJp, (puntatore+k)->altreVendite, (puntatore+k)->venditeGlobali);

            k++;

    }
    }

    fclose(fp);
    return 1;
}
