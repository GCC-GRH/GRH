#include<stdio.h>
void main(){
    int n,sum=0;
    printf("\n Please enter the value of N");
    scanf("%d",&n);
    while(n!=0){
        sum+=n;
        n--;
    }
    printf("\n The value of N:: %d",sum);
}