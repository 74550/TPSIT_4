#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LUNG 1024
#define NPERS 38


typedef char* Stringa;
typedef struct dati{
    int giorno;
    int mese;
    int anno;
    Stringa cognome;
    int quota;
}Dati;

typedef struct pagato{
    Stringa cognome;
    int quota;
}Pagato;

int main() {
    FILE *fp;
    fp = fopen("4AROB_GITA.csv", "r");

    Stringa riga;
    Dati *a;
    a = (Dati *) malloc(NPERS * sizeof(Dati));   //puntatore a struttura con locazione dinamica

    if (fp == NULL) {
        printf("errore nell'apertura del file");
    } else {
        printf("sono dentro");

        int k = 0;
        riga = (Stringa) malloc(LUNG * sizeof(char));

        int incassi=0;

        while (fgets(riga, LUNG, fp)) {
            (a+k)->giorno=atoi(strtok(riga,"/"));
            (a+k)->mese=atoi(strtok(NULL,"/"));
            (a+k)->anno=atoi(strtok(NULL,";"));
            (a + k)->cognome = strdup(strtok(NULL, ";"));    //carattere divisore ,
            (a + k)->quota = atoi(strtok(NULL, ";"));
            printf("\n%d/%d/%d, %s, %d",(a+k)->giorno,(a+k)->mese,(a+k)->anno,(a+k)->cognome, (a+k)->quota);

            incassi=incassi+(a+k)->quota;

            riga = (Stringa) malloc(LUNG * sizeof(char)); // spazio di nuovo a 1024 per la nuova iterazione del ciclo
            k++;



        }
        printf("\n\n l'incasso totale è %d",incassi);

        if(incassi==2200){
            printf("\n\ncorretto");
        }else if(incassi<2200){
            int soldiMancanti=2200-incassi;
            printf("\n\n i soldi mancanti sono %d",soldiMancanti);
        }else {
            int soldiInPiu=incassi-2200;
            printf("\n\n i soldi in più sono %d",soldiInPiu);
        }

        Stringa nomeDaCercare=(char*) malloc(NPERS * sizeof(char));
        printf("\ninserisci un nome: ");
        fflush(stdin);
        gets(nomeDaCercare);
        int somma=0;
        for (int k = 0; k< NPERS; k++) {
            if(strcmp(nomeDaCercare,(a+k)->cognome)==0){
                somma=somma+(a+k)->quota;
            }
        }
        printf("\n%s %d",nomeDaCercare,somma);

        printf("\n");

        Pagato *i;
        i = (Pagato *) malloc(NPERS * sizeof(Dati));
        for (int k = 0; k< NPERS; k++) {
            printf("\n%s %d",(a+k)->cognome,(i+k)->quota);
            if((i+k)->quota<100){
                printf("\n%s da controllare",(a+k)->cognome);
            }
        }
        free(i);

    }
    fclose(fp);

    free(a);
}
