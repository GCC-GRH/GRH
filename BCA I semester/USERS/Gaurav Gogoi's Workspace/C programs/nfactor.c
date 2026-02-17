#include<stdio.h>
#include<stdlib.h>
void main(){
    system("cls");
    int n;
    register int i; // Register keyword is used to allocate and reserve spaces from cache memory for frequent access of a variable. It is not compulsory. Adv: Faster access time.
    printf("Please enter the number to find it's factor\n==>");
    scanf("%d",&n);
    for(i=1;i<n;i++){
        if(n%i==0)
            printf("\t%d",i);
    }
}