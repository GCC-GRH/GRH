#include<stdio.h>
#include<conio.h>
void main(){
    float a,b;
    printf("Enter first number:" );
    scanf("%f",&a);
    printf("Enter second number:" );
    scanf("%f",&b);
    if(a==b){
        printf("\n\nBoth are same.");
    }
    else{
        printf("\nFirst Nunber: %f",a);
        printf("\nSecond Number: %f",b);
        a=a+b;
        b=a-b;
        a=a-b;
        printf("\nFirst number (new): %f",a);
        printf("\nSecond number (new): %f",b);
    }
    getch();
}