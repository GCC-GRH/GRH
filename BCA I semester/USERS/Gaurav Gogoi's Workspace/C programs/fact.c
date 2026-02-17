#include<stdio.h>
void main(){
    int num,fact=1;
    printf("\n Please enter a number : ");
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        fact*=i;
    }
    printf("\n The result of the factorial is %d",fact);
}