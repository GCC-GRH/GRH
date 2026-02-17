#include<stdio.h>
void main(){
    int num[10],result=0;
    printf("Please enter your values :");
    for(int i=0;i<=9;i++){
        scanf("%d",&num[i]);
        result+=num[i];

    }
        printf("The summation value is %d",result);
}