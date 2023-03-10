#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define NMAX 5

void scambio(int *x, int *y) {
    int t;

    t = *x;
    *x = *y;
    *y = t;
}

int main(){
    int vett[5]={5,3,9,12,2};
    int *p=vett;
    int k, sup;
    for (sup = NMAX-1; sup > 0; sup--) {
        for (p = vett; p< vett + sup ;p++) {
            if (*p > *p+1){
                scambio(&*p,&*p+1);
            }

        }
    }
    for (p = vett; p < vett+NMAX ; p++) {
        printf("%d ",*p);
}
}
