#include<stdio.h>
void main(){
    int number, status;
    printf("Please enter your number to check if it is divisible by two or not: ");
    scanf("%d",&number);
    if (number!=0)
    {
        
        status=number%2; // IF value is evaluated as zero, this means number is divisible by 2
    if(status!=0){
        printf("\n %d is Not divisible number by 2",number);
    }else{
        printf("\n %d is divisible number by 2",number);
    }
    }else{
        printf("\n No value entered! Program exited :)");
    }
    
}