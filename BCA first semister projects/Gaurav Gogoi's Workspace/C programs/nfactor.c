#include<stdio.h>
void main(){
    int n;
    register int i;
    printf("Please enter the number to find it's factor\n==>");
    scanf("%d",&n);
    for(i=1;i<n;i++){
        if(n%i==0)
            printf("\t%d",i);
    }
}