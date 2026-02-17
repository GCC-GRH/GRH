#include<stdio.h>
void main(){
    int cnt=0,num,temp;
    printf("\n Please enter your number : ");
    scanf("%d",&num);
    temp=num;
    while(temp!=0){
        temp/=10;
        cnt++;
    }
    printf("\n The digit count for number %d is %d",num,cnt);
}