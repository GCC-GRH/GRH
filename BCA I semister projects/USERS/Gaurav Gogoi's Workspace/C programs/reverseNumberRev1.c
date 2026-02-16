#include<stdio.h>

int reverseNum(int a){  // Function Definition
    int temp=a;
    int r;
    int result=0;
    int b=1;
    while(temp!=0){
        r=temp%10;
        result=(result*b)+r;
        b=10;
        temp/=10;
    }
    return result;
}

void main(){
    int a;
    printf("Please enter your number : \n");
    scanf("%d",&a);
    printf("The reverse number is %d",reverseNum(a));
}