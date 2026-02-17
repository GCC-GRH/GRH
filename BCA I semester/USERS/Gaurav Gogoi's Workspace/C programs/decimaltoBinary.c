#include<stdio.h>
void main(){
    int num,show_num,remainder,value=0,position=1;
    printf("\n Please enter your decimal value to convert it into Binary");
    scanf("%d",&num);
    while(num!=0){
        remainder=num%2;
        value+=remainder*position;
        position*=10;
        num/=2;

    }
    printf("\n The converted value is %d",value);
}