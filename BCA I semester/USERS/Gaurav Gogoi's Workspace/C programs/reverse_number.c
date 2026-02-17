#include<stdio.h>
void main(){
    int num,r,value=0;
    printf("\n Please specify your number: ");
    scanf("%d",&num);
    while(num!=0){
        r=num%10;
        value=value*10+r;
        num/=10;

    }
    printf("\n Value in reversed :: %d",value);
}