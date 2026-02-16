#include<stdio.h>
int *fun(){
    static int i=10; 
    return (&i);
}
void main(){
    int *x=fun();
    printf("\n%p",x);
    printf("\n%d",*x);
}