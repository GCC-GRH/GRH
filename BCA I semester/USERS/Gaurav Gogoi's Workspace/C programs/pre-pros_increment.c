#include<stdio.h>
void main(){
    int a; 
    printf("\n Please enter your number");
    scanf("%d",&a);
    printf("The value upon preincrement is %d",++a);
    printf("\n post incremented %d",a++);
    printf("\n Fetching the post incremented value %d",a);
}