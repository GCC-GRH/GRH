#include<stdio.h>
void main(){
    char a,b;
    printf("\n Enter one lowercase character value : \n");
    a=getchar();
    printf("The character entered is : ");
    putchar(a);

    printf("\n Character in uppercase == ");
    putchar(a-32); // 'a' - 'A' = 97 - 65 = 32 in ASCII value of character, there is a value difference of 32 between same letter with case. If we subtract ascii value of any lowercase and uppercase of same character, we get value difference of 32.



}