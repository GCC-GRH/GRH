#include<stdio.h>
int sum(int a,int b);
int main(){
  int num1,num2,add;
  printf("Enter the two number:\n");
  scanf("%d %d",&num1,&num2);
  add=sum(num1,num2);
  printf("The sum of two number is %d\n",add);
  return 0;
}
int sum(int a,int b){
    int result;
    result=a+b;
    return result;
}