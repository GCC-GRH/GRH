#include<stdio.h>
int *fun(){
    static int x=10;
    return &x;
};

void main(){
    int *p;
    p=fun();
    printf("\n The pointed address obtained from the pointer %p",p);
    printf("\n The value obtained from function variable is %d",*p);
}