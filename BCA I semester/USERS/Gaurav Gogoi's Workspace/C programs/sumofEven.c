#include<stdio.h>
void main(){
    int num;
    int i=1;
    int sum=0;
    printf("\n Please enter your number : ");
    scanf("%d",&num);
    while (i<=num){
        if(i%2==0){
            sum+=i;
        }
        i++;
    }
    printf("\n The even sum of %d is %d",num,sum);
}