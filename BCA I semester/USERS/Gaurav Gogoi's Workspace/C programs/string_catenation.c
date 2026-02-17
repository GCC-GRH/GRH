#include<stdio.h>
#include<string.h>
void main(){
    char str1[50],str2[50];
    printf("Please enter a string 1 : ");
    gets(str1);
    printf("\nPlease enter a second string 2 : ");
    gets(str2);
    strcat(str1, str2);
    puts(str1);
}