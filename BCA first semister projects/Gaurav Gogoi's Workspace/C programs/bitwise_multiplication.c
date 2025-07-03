#include<stdio.h>
void main(){
    long num,tempnum;
    printf("\n Enter your given number: ");
    scanf("%ld",&num);
    tempnum=num;
    num=num<<2;
    printf("\n %ld x 4 = %ld", tempnum, num);
}