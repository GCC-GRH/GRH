#include<stdio.h>
void main(){
    int value,sum=0;
    printf("\n Please enter the value of N (Must be ODD): ");
    scanf("%d",&value);
    if(value%2==0){
        while(value%2==0){
        printf("\n Please enter an odd integer: ");
        scanf("%d",&value);
        }
    }
    printf("\n The Odd numbers are: ");
    for(int i=1;i<=value;i+=2){
        sum=sum+i;
        printf("%d ",i);
        if(i==value){
            printf("\n");
        }
    }
    printf("The summation of ODD number is : %d",sum);
}