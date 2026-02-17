#include<stdio.h>
void main(){
    int a,b;
    a=43;
    b=65;
    printf("Before swapping a::%d and b::%d",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\nAfter swapping a::%d and b::%d",a,b);
}