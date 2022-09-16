#include <stdio.h>
#define LUNG 1024
#include <string.h>

typedef char Stringa [LUNG];

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
    Stringa riga;
    if(fp==NULL){
        printf("errore nell'apertura del file");
        return 0;
    }
    printf("sono dentro");

    while(!feof(fp)){
        fgets(riga, LUNG, fp);
        printf("%s",riga);

    }

    fclose(fp);
    return 0;
}
