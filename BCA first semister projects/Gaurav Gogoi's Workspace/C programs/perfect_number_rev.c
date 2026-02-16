#include<stdio.h>
void main(){
    int num,sum=0;
    printf("\n Please enter your number :");
    scanf("%d",&num);
    for(int i=1;i<num;i++){
        if(num%i==0){
            sum+=i;
        }
    }
    if(num==sum){
        printf("\n It is a perfect number");
    }else{
        printf("\n It is not a perfect number");
    }
}