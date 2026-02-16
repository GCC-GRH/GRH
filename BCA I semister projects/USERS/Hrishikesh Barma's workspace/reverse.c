#include<stdio.h>
int main(){
int num,r;
printf("Enter a number:\n");
scanf("%d",&num);
while(num>0){
    r=num%10;
    printf("%d",r);
    num=num/10;
}
return 0;
}