// Q8. Write a C program to find the largest of three numbers.
#include<stdio.h>
#include<conio.h>
void main()
{
	int num1,num2,num3;
	printf("please enter first number: ");
	scanf("%d",&num1);
	printf("please enter sec number: ");
	scanf("%d",&num2);
	printf("please enter third number: ");
	scanf("%d",&num3);
	if(num1>=num2 && num1>=num3){
		printf("\n first number is largest");
	}
	else if(num2>=num1 && num2>=num3){
		printf("\n second number is largest");
		}
		else{
		printf("\n third number is largest");
		}
	getch();	
}
