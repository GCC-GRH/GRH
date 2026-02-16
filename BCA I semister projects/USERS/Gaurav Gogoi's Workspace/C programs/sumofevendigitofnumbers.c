#include<stdio.h>
void main(){
    int num,r,temp,sum=0;
    
    printf("Please enter a number:");
    scanf("%d",&num);
    temp=num;
    while(num!=0){
        r=num%10;
        if(r%2==0)
            sum+=r;
        num/=10;

    }
    printf("\n The summation of each digit of %d is %d",temp,sum);
}