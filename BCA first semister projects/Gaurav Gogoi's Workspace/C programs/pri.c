#include<stdio.h>
void main(){
    int num,factors=0;
    printf("Please enter a number");
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
        if(num%i==0){
            factors++;
        }
    }
    if(factors==2){
        printf("\n It is a prime number");
    }else{
        printf("\n It is a non-prime number");
    }
}