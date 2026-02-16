#include<stdio.h>
void main(){
    int a=10,b=20;
    printf("\n The value of var a and b before swap is %d and %d respectively",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("\n The value of var a and b after swap is %d and %d respectively",a,b);
}