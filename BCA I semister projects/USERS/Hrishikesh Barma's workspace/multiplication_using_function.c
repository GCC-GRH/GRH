#include<stdio.h>
int multiplication(int a,int b);
int main(){
int num1,num2,multiply;
printf("Enter the two number:\n");
scanf("%d %d",&num1,&num2);
multiply=multiplication(num1,num2);
printf("The multiplication of given two number is %d\n",multiply);
return 0;
}
int multiplication(int a,int b){
    int result;
    result=a*b;
    return result;
}