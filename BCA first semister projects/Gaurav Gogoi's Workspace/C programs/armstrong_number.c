#include<stdio.h>
void main(){
    int num,r,temp,sum=0,s=1;
    printf("\n Please enter your value:");
    scanf("%d",&num);
    temp=num;
    while(num!=0){
        r=num%10;
        s=(r*r*r);
        sum+=s;
        num/=10;
    }
    sum==temp ? printf("\n It is a armstrong number ") : printf("\n It is not an armstrong number");
}