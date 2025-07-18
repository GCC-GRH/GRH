#include<stdio.h>
void main(){
    int a;
    printf("\n Please enter a value to check if it is positive or negative");
    scanf("%d",&a);
    if(a>0){
        printf("\n The given value is positive!");
    }else{
        printf("\n The given value is negative");
    }
}