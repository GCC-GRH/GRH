#include<stdio.h>
#include<conio.h>
int main(){
    char ch;
    clrscr();
    printf("Enter a character:",ch);
    scanf("%c",&ch);
    printf("\n The ASCII value of the %c is %d",ch,ch);
    return ch;
}