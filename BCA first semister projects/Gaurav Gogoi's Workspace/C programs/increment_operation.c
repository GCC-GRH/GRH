#include<stdio.h>
void main(){
    int a=10,b;
    b=a++; // The value of a is added to b first then it is increased.
    printf("\n The value of a in posfix increment is %d",b);
    a=10;
    b=++a; // The value of a is increased first then added to be.
    printf("\n The value of a in prefix increment is %d",a,b);
}