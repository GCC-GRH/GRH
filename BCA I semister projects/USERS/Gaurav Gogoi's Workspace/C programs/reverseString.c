#include<stdio.h>
void main(){
    int len=0,i,temp;
    char s1[10],s2[10];
    printf("\n Please enter original string : ");
    gets(s1);
    while(s1[len]!='\0'){
        len++;
    }
    temp=len-1;
    for(i=0;i<len;i++){
        s2[i]=s1[temp--];
    }
    s2[len]='\0';
    printf("\n The string in reverse order is %s",s2);
}