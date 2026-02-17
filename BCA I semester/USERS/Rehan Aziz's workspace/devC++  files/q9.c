// Q9. Write a C program to check if a number is even or odd
#include<stdio.h>
#include<conio.h>
void main()
{
	int num1;
	printf("please input a number: ");
	scanf("%d",&num1);
	if(num1%2==0){
	printf("\n the number is evenn");
	}
	else {
		printf("\n the number is odd");	
	}
	getch();
}
