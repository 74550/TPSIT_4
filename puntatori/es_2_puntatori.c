

int main(){
int a[3]={1,2,3};
int i;
int *p;
p=a;
for(i=0;i<3;i++){
    printf("%d ",a[i]);
}

printf("\n");

for(i=0;i<3;i++){
    printf("%d ",*(a+i));
}

printf("\n");

for(p=a;p<a+3;p++){
    printf("%d ",*p);
}
}
