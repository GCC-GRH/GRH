#include<stdio.h>
#include<string.h>
void main(){
    char s1[10];
    char s2[10];
    printf("Please enter for string 1: ");
    gets(s1);
    printf("\nPlease enter for string 2: ");
    gets(s2);
    strcat(s1,s2);
    printf("\n%s",s1);
}