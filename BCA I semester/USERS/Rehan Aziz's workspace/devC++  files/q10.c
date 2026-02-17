// Q 10. Write a C program to check if a number is positive, negative, or zero..
#include<stdio.h>
#include<conio.h>
void main(){
	int num;
	printf("please input a number: ");
	scanf("%d",&num);
	if(num>0){
		printf("the number is positive");
	}
	else if(num==0){
		printf("the number is zero");
	}
	else{
		printf("the number is negative");
	}
	getch();
}
