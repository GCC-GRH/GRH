#include<stdio.h> //This program is a simplified conditional statement which uses ternary operators
void main(){
    int age;
    printf("\n Please enter your age: ");
    scanf("%d",&age);
    age >= 18 ? printf("\n Tum bara admi hai :)") : printf("\n tum chota admi hai :( ");
}