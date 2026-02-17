#include<stdio.h>
#include<string.h>
void ispalindrome(char *x){
    
    char *str_ptr;
    str_ptr=x;
    int strlwn=strlen(str_ptr);
    int i,j,flag=0;
    for(i=0,j=strlwn-1;i<strlwn/2;i++,j--){
        if(str_ptr[i]!=str_ptr[j]){
            flag=1;
            break;
        }
    }
    (flag==0) ? printf("\n It is a valid string Palindrome"): printf("\n It is not a string palindrome");
}
void main(){
    char str[20];
    printf("\n Please enter a string value : ");
    gets(str);
    ispalindrome(str);
}