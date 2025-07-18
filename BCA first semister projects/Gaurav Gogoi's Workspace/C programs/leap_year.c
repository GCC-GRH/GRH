#include<stdio.h>
void main(){
    int year;
    printf("\n Please enter your year: ");
    scanf("%d",&year);
    if(year%400==0 || year%100!=0 && year%4==0){
        printf("\n It is a leap year ");
    }else{
        printf("\n It is not a leap year ");
    }
}