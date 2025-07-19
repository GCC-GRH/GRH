#include<stdio.h>
#include<math.h>
void main(){
    int a,n,outcome;
    printf("\n Please enter your number to check if its is a perfect square root or not :");
    scanf("%d",&n);
    a=sqrt(n);
    outcome=n-a*a;
    if(outcome==0){
        printf("\n This is a perfect squre root number!");
    }else{
        printf("\n This is not a perfect square root number!");
    }

}