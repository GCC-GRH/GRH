#include<stdio.h>
void main(){
    int base,exponent,pow=1;
    printf("Please enter the value of number  : ");
    scanf("%d",&base);
    printf("\n Please enter the power of your value : ");
    scanf("%d",&exponent);
    for(int i=1;i<=exponent;i++){
        pow*=base;
    }
    printf("\n The power calculation is %d",pow);
    
}