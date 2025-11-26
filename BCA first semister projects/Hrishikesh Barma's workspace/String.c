#include<stdio.h>
#include<string.h>
void main(){
    char str1[50],str2[50];
  printf("Please enter a  first string:");
  gets(str1);
  printf("\n Please enter a second string:");
  gets(str2);
strcat(str1,str2);
puts(str1);
}