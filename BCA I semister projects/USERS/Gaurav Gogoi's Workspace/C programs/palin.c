#include<stdio.h>
void main(){
    int num,pros_num,res=0,base=1;
    printf("\n Please enter a number : ");
    scanf("%d",&num);
    pros_num=num;
    while(pros_num!=0){
        int r=pros_num%10;
        res=(base*res) + r;
        base=10;
        pros_num/=10;

    }
    printf("\n%d",res);
    if(num==res){
        printf("\n It is a palindrome number");
    }else{
        printf("\n It is not a palindrome number");
    }
}