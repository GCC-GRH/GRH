#include<stdio.h>
#include<math.h>
void main(){
    float p,r,t,ci;
    printf("Please enter principle amount : ");
    scanf("%f",&p);
    printf("\nPlease enter the rate : ");
    scanf("%f",&r);
    printf("\nPlease enter the time : ");
    scanf("%f",&t);
    ci=p*(pow((1+r/100),t));
    printf("\n The value of compoud interest is %f",ci);
}