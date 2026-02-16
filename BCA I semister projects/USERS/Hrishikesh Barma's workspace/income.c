#include<stdio.h>
int main(){
    int P,R,T,x,I;
    printf("enter the principal:\n");
    scanf("%d",&P);
    printf("enter the rate of interest:\n");
    scanf("%d",&R);
    printf("enter the time(in year):\n");
    scanf("%d",&T);
    x=P*R*T;
    I=x/100;
    printf("the interest of the income are %d",I);
    return 0;
}
