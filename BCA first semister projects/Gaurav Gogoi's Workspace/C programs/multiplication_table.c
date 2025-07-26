#include<stdio.h>
void main(){
    int n;
    printf("\n Please enter your multiplication Table : ");
    scanf("%d",&n);
    for (int i=1; i<=10; i++)
        printf("\n %d x %d = %d",n,i,(n*i));
    
}