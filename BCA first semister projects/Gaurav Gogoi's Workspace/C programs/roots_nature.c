#include<stdio.h>
void main(){
    int a,b,c,d; //coefficients of a quadratic equation
    printf("\n Please enter coeffient a b and c respectively : ");
    scanf("%d %d %d",&a,&b,&c);
    printf("The given quadratic equation is %dx2 + %dx + %d = 0",a,b,c);
    d=(b*b)-(4*a*c);
    if(d>0){
        printf("\n Real and distinct roots");
    }else{
        if(d<0){
            printf("\n Imaginary and distinct roots");
        }else{
            if(d=0){
                printf("\n Real and Equal roots");
            }else{
                printf("Invalid roots");
            }
        }
    }
}