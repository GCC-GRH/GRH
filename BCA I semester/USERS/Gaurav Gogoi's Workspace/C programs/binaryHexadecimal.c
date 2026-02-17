#include<stdio.h>
void main(){
    int num,r,temp,value=0,i=1;
    printf("\n Please enter value in Binary : ");
    scanf("%d",&num);
    temp=num;
    while(num!=0){
        r=num%10;
        value+=r*i;
        i*=2;
        num/=10;
    }
    printf("\n The Binary value %d in decimal is ==>(%d)base10",temp,value);
    printf("\n The Binary value %d in hexadecimal is ==>(%X)base16", temp, value);
} 