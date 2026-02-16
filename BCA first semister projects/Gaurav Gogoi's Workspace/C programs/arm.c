#include<stdio.h>
void main(){
    int num,r,arm_res=0,cnt_digit=0,temp,pow=1;
    printf("\n Please enter a number to verify if it is Armstrong : ");
    scanf("%d",&num);
    temp=num;
    while(temp!=0){
        cnt_digit++;
        temp/=10;
    }
    temp=num;
    while(temp!=0){
        r=temp%10;
        for(int i=1;i<=cnt_digit;i++){
            pow*=r;
        }
        arm_res+=pow;
        temp/=10;
        pow=1;
    }
    if(arm_res==num){
        printf("\n It is an Armstrong number");
    }else{
        printf("\n It is not an Armstrong number");
    }

}