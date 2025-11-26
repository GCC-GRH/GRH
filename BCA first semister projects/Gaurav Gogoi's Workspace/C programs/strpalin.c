#include<stdio.h>
#include<string.h>
void main(){
    int i,j,flag; // loop iterators
    char str[50]; // string var
    printf("Please enter a string to check if it is a palindrome : ");
    gets(str);
    for(i=0,j=strlen(str)-1;i<(strlen(str)/2);i++,j--){
        if(str[i]!=str[j]){
            flag=1;
            break;
        }
    }
    (flag==1) ? printf("\n It is not a palindrome") : printf("\n It is a palindrome");
}