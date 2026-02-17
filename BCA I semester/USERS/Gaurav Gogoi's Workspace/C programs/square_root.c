#include<stdio.h>
#include<math.h>
int main(){
printf("\n This program fascillates printing of the square root value of a number using the math h header file");
int a;
printf("\n Please enter your number: ");
scanf("%d",&a);
printf("\n The square root value of the given number %d is %f", a, sqrt(a));
return 0;
}