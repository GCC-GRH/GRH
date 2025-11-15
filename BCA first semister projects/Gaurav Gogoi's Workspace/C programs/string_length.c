#include<stdio.h>
void main(){
    char val[10];
    int count=0; //iterator
    printf("Please enter your string: ");
    gets(val);
    while(val[count]!='\0'){
        count++;
    }
    printf("\n The number of characters within the string is %d",count);
}