#include<stdio.h>
void main(){
    int x,y;
    printf("\n Please enter a number from your keyboard : ");
    scanf("%d",&x);
    x=x<<2;
    y=x;
    printf("\n The left shifted data is = %d ",y);
}