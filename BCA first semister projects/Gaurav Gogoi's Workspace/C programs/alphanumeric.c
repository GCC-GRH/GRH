#include<stdio.h>
#include<ctype.h>
int ch;
void main(){
    printf("\n Please enter your character :");
    ch=getchar();
    if(isalnum(ch)){
        printf("\n It is a alpha-numeric character");
    }else{
        printf("\n It is not alpha-numeric character");
    }
}