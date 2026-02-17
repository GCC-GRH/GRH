
//Q7> Write a C program to find the largest of two numbers.
#include<stdio.h>
#include<conio.h>
void main(){
	int num1, num2;
	printf("please enter first number: ");
	scanf("%d",&num1);
	printf("\n please enter second number: ");
	scanf("%d",&num2);
	if (num1>num2){
		printf("The larger number is: %d",&num1);
	}
		else if(num2>num1){                        //2bar else dile first else tut else if dibo lagibo and sec else tut eku condition dibo nuari
			printf("The larger number is: %d",num2);
		}
		else{
			printf("Both the numbers are equal");
		}getch();
}
