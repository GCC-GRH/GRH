#include<stdio.h>
#include<string.h>
void main(){
    char str[50];
    printf("\n Please enter a string : ");
    gets(str);
    for(int i=0;i<strlen(str);i++){
        printf("\n %c == %d",str[i],str[i]);
    }

}