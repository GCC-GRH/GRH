#include<stdio.h>
void main(){
    int n,temp;
    int r, base=1,result=0;
    printf("\n Please enter a number to reverse : ");
    scanf("%d",&n);
    temp = n;
    while(temp!=0){
        r=temp%10;
        result=(result*base) + r;
        base=10;
        temp/=10;
    }
    printf("\n%d",result);
}