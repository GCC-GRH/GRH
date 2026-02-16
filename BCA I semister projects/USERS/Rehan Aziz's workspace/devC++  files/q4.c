// Q4. Write a C program to take two numbers as input and print their product.
#include<stdio.h>
#include<conio.h>
void main(){
	int num1,num2,product;
	printf("\n Enter the first number: ");
	scanf("%d",&num1);
	printf("\n Enter the second number: ");
	scanf("%d",&num2);//yaar loi correct koru bbut nxt part wrong koru
	product=num1*num2;
	printf("\n Their product is: %d",product);// ei line tut bhul hoi so remember
	getch();
}
