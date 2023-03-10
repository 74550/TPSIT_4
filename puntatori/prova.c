#include <stdio.h>

int main(){
int *p1;
int *p2;
printf("%p\n",p1);
*p1=*p1+1;
printf("%p",p1);
}
