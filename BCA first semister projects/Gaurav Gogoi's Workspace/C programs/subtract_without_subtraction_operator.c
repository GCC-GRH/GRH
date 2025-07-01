#include<stdio.h>
int main()
{
    printf("\n This program fascilates subtraction of two numbers which is user defined using bitwise not operator or without the default subtraction operator");
    int a,b, sum;
    printf("\n Enter the first number: ");
    scanf("%d",&a);
    printf("\n Enter the second number: ");
    scanf("%d",&b);
    sum=a+~b+1;
    printf("\n The differnce value is %d", sum);
    return 0;
}