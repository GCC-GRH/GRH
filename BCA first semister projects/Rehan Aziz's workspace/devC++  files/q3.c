// Q3. Write a C program to take two numbers as input and print their sum..
#include<stdio.h>
#include<conio.h>
void main(){
	float a,b,sum;
	printf("Enter the two numbers: ");
	scanf("%f,%f",&a,&b);
	sum=a+b;
	printf("\n The sum is: %f",sum);
	getch();
}
