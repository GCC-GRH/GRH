#include<stdio.h>
int add(int a,int b);
int main(){
int a=5,b=9,sum;
sum=add(a,b);
printf("\n The result is %d", sum);
return 0;
}
int add(int a,int b){
 int result;
result=a+b;
return result;
}