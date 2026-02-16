#include<stdio.h>
void main(){
    int i=1,n,factorial=1;
    printf("Please enter a value to find its factorial: ");
    scanf("%d",&n);
    while(i<=n){
        factorial=factorial*i;
        i++;
    }
    printf("\n Factorial of the given number %d is %d ", n, factorial);
}