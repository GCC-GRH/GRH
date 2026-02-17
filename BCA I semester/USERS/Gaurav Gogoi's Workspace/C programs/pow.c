#include<stdio.h>
void main(){
    int base,exponent,result=1;
    printf("\n Please enter the value of base :");
    scanf("%d",&base);
    printf("\n Please enter the value of exponent :");
    scanf("%d",&exponent);
    for(int i=1;i<=exponent;i++){
        result*=base;
    }
    printf("\n The result is %d",result);
}