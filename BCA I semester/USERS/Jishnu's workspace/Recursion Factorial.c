#include<stdio.h>
#include<math.h>
int factorial(int i){
    if (i==0)
        return 1;
    else
        return i*factorial(i-1);
};
void main(){
    int i,fact;
    printf("Enter a nunber: ");
    scanf("%d",&i);
    printf("\n i:%d\n",i);
    fact=factorial(i);
    printf("Factorial of i: %d",fact);
}
