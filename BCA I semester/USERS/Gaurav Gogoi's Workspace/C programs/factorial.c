#include<stdio.h>
int main(){
    int factorial=1;
    int i,num;
    printf("\n This program prints the factorial of a given number "); //Source code by Gaurav gogoi
    printf("Please enter your number: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++){
        factorial=factorial*i;
    }
    printf("\n The factorial of %d is %d",num,factorial);
    return 0;
}