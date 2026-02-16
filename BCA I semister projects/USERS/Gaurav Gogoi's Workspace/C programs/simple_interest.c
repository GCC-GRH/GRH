#include<stdio.h>
void main(){
    float p,r,t,si;
    printf("\n Please enter the principle amount value ");
    scanf("%f",&p);
    printf("\n Please enter the rate amount value ");
    scanf("%f",&r);
    printf("\n Please enter the duration value ");
    scanf("%f",&t);
    si=(p*r*t)/100;
    printf("\n The value obtained is %f ",si);


}