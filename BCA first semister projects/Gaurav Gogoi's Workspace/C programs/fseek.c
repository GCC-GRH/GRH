#include<stdio.h>
void main(){
    FILE* fp=fopen("message.txt","r");
    fseek(fp,0,SEEK_END);
    printf("%ld",ftell(fp));
    fclose(fp);
}