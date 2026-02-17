#include<stdio.h>
#include<string.h>
void main(){
    char s[20];
    int i,j,flag=0;
    printf("\n Please enter a string : ");
    gets(s);
    for(i=0,j=strlen(s)-1;i<strlen(s)/2;i++,j--){
        if(s[i]!=s[j]){
            flag=1;
            break;
        }
    }
    if(flag==0)
        printf("\n It is a valid string Palindrome");
    else
        printf("\n It is not a string palindrome");
}