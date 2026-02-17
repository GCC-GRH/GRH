// Q 11. Write a C program to check if a character is a vowel or consonant.
#include<stdio.h>
#include<conio.h>
void main(){
	char a;
	printf("please enter an alphabet: ");
	scanf("%c",&a);
	if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u' || a=='A' || a=='E' || a=='I' || a=='O' || a=='U'){
	printf("the given character is a vowel");
}
	else{
		printf("the given character is a consonant");
	}
	getch();
}
