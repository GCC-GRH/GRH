#include<stdio.h>
void main(){
    char str[100],ch;
    int count=0;
    printf("\n Please enter your string : ");
    while(1){
        ch=getch();
        if(ch==13)
            break;
        str[count]=ch;
        count++;

    }
    str[count]='\0';
    printf("\nEntered String : %s ",str);
}