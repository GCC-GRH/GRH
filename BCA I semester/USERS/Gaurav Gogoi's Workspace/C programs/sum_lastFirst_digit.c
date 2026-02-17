#include <stdio.h>
void main(){
    int num,r,sum,first,last;
    printf("Please enter your value : ");
    scanf("%d",&num);
    r=num%10;
    last=r;
    num/=10;
    sum=r;
    while(num!=0){
        r=num%10;
        first=r;
        num/=10;
    }
    sum+=r;
    printf("The summation of %d and %d is %d",first,last,sum);
}