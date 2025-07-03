#include<stdio.h>
#include<conio.h>
int main(){
    char a,b;
    
    printf("\n Enter one character : ");
    scanf("%c",&a);
    printf("Input character is : %c",a);
    fflush(stdin);
    printf("\n Enter second character: ");
    b=getchar();
    printf("\n ASCII value of character %c is %d", b,b);

    return 0;
}