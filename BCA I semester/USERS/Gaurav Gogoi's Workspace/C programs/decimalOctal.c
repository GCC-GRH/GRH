#include<stdio.h>
void main(){
    int num,temp,value[100],octal=0,i=0,base=0;
    printf("\n Please enter your number: ");
    scanf("%d",&num);
    temp=num;
    while(num!=0){
        value[i]=num%8;
        num/=8;
        i++;
    }
    while(i>0){
        octal=(base*octal)+value[i];
        base=10;
        i--;
    }
    printf("The value of Decimal %d in Octal system is : %d ",temp,octal);

}