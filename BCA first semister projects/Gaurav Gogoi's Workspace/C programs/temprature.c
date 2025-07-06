#include<stdio.h>
void main(){
    float celcius,fehrenheit;
    printf("\n Please enter the temperature in celcius: ");
    scanf("%f",&celcius);
    fehrenheit = (1.8 * celcius) + 32;
    printf("\n The value of fehrenheit is %f",fehrenheit);
}