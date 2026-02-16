#include<stdio.h>
void main(){
    char data[50];
    FILE* fp=fopen("message.txt","r");
    if(fp!=NULL){
    fgets(data,50,fp);
    printf("%s",data);
    }else{
        printf("\n Error occured while creating or fetching file contents");
    }
}