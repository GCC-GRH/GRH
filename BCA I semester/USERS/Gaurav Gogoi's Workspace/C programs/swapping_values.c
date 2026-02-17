#include<stdio.h>
void main(){
    int a, b, temp;
    printf("\n Enter the value of A :\n");
    scanf("%d",&a);
    printf("\n Enter the value of B :");
    scanf("%d",&b);
    printf("\n Before Swapping the values of the variable");
    printf("\n Value of a=%d and value of b=%d",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("\n The values after swapped, value of a is %d and value of b is %d ", a, b);


}