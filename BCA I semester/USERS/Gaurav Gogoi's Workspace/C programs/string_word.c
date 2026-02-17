#include<stdio.h>
void main(){
    char val[50];
    int count=0; //iterator and counter
    int words=1;
    printf("Please enter your string: ");
    gets(val);
    while(val[count]!='\0'){
        count++;
        if(val[count]==' '){
            words++;
        }

    }
    printf("\n The number of characters within the string is %d and number of words is %d",count,words);
}