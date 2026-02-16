#include<stdio.h>
#include<stdlib.h>
void main(){
    int b,a,c,d;
    printf("Enter value of a b and c of a quadratic eqn respectively: ");
    scanf("%d %d %d",&a,&b,&c);
    d=(b*b) - (4*a*c);
    if(d>0){
        printf("\nRoots are real and unequal");
    }else if(d==0){
        printf("\nRoots are real and equal");
    }else if(d<0){
        printf("\nComplex roots");
    }
}