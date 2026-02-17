#include<stdio.h>
void main(){
    int year;
    printf("\n Please enter your year\n==>");
    scanf("%d",&year);
    if(year%400==0 || year%100!=0 && year%4==0 ){
        printf("\n The year you've entered is a leap year");
    }else{
        printf("\n The year you've entered is not a leap year");
    }
}