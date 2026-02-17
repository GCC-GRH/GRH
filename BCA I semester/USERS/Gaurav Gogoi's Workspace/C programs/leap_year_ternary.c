#include<stdio.h>
void main(){
    printf("Please enter your year : ");
    int x;
    scanf("%d",&x);
    (x%400==0 || x%100!=0 && x%4==0) ? printf("\n It is a leap year") : printf("\n It is not a leap year");
}