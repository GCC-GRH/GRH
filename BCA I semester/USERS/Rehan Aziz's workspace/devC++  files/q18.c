// Q18. Write a C program to check whether a number is prime.
#include<stdio.h>
#include<conio.h>
void main(){
	int num;
	printf("Please input a number: ");
	scanf("%d",&num);
	if(num%1==0 && num%num==0){
		printf("the number is a prime number");
	}
	else{
		printf("the nunber isnt a prime number");
	}
	getch();
}
