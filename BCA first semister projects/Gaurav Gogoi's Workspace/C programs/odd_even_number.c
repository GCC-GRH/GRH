#include<stdio.h>
int main(){
    printf("\n This program checks whether a given number is even or odd");
    int number,remainder;
    printf("\n Enter the number you want to check:");
    scanf("%d",&number);
    remainder=number%2;
    if(remainder==0){
        printf("\n The number is even");
    }
    else{
        printf("\n The number is odd");
    }
    return 0;
}