#include<stdio.h>
void main(){
    int a,b,max;
    printf("\n Please enter your first number : ");
    scanf("%d",&a);
    printf("\n Please enter your second number : ");
    scanf("%d",&b);
    if(a>b){
        max=a;
    }else{
        max=b;
    }
    printf("\n The maximum value is %d",max);
}