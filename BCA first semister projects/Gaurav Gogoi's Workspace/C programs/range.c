#include<stdio.h>
void main(){
    int x;
    printf("\n Please enter a number between the range of 30 and 100 : ");
    scanf("%d",&x);
    printf("%d",(x>30)&&(x<100));
}