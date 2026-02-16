#include<stdio.h>
#include<string.h>
void main(){
    int flag=0;
    char s[10];
    printf("\n Please enter your string: ");
    gets(s);
    int i=0;
    int j=strlen(s)-1;
    while(j>=0){
        if(s[i]!=s[j]){
            flag=1;
        }
        i++;
        j--;
    }
    (flag==0) ? printf("\n Palindrome string") : printf("\nNot a palindrome string");
}