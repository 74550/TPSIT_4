#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TIMESLICE 30 // time slice di 30 ms

// struttura del processo
struct Process {
    int PID;
    char STATO[10];
    int TIME;
    struct Process *next;
};

// testa della lista
struct Process *NL = NULL;
struct Process *RL = NULL;
struct Process *TL = NULL;

// funzione per creare un nuovo processo
struct Process* newProcess(int PID, int TIME) {
    struct Process* temp = (struct Process*) malloc(sizeof(struct Process));
    temp->PID = PID;
    temp->TIME = TIME;
    strcpy(temp->STATO, "new");
    temp->next = NULL;
    return temp;
}

// funzione per spostare i processi dalla NL alla RL
void moveProcesses() {
    struct Process *temp = NL;
    while (temp != NULL) {
        strcmp(temp->STATO , "ready");
        RL = temp;
        NL = temp->next;
        temp->next = NULL;
        temp = NL;
    }
}

// funzione per assegnare i processi alla CPU
void assignProcesses() {
    struct Process *temp = RL;
    while (temp != NULL) {
        strcmp(temp->STATO , "execute");
        temp->TIME -= TIMESLICE;
        if (temp->TIME <= 0) {
            strcmp(temp->STATO , "terminated");
            TL = temp;
            RL = temp->next;
            temp->next = NULL;
        }
        temp = RL;
    }
}

int main() {
    // creazione dei processi e inserimento nella NL
    NL = newProcess(1, 50);
    NL->next = newProcess(2, 100);
    NL->next->next = newProcess(3, 150);
    NL->next->next->next = newProcess(4, 200);
    // spostamento dei processi dalla NL alla RL
    moveProcesses();
    // assegnamento dei processi alla CPU
    assignProcesses();
    // stampa dei processi nella TL
    struct Process *temp = TL;
    while (temp != NULL) {
        printf("PID: %d, STATO: %s, TIME: %d\n", temp->PID, temp->STATO, temp->TIME);
        temp = temp->next;
    }
    return 0;
}
