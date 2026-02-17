#include<stdio.h>
int *fun(){
    static int a=10;
    return (&a);
}

void main(){
    int* p;
    p=fun();
    printf("\n The address of the value from function variable is %p",p);
    printf("\n The value obtained from the address is %d",*p);
}