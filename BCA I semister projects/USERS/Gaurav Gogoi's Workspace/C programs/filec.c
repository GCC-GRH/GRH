#include<stdio.h>
void main(){
    char data[500];
    FILE* fp=fopen("message.txt","w");
    if(fp!=NULL){
    printf("Please enter your text:\n Must be under length 500 \n");
    gets(data);
    if(data!=NULL){
        fputs(data,fp);
        fputs("\n",fp);
        printf("\n\nData stored successfully");
        fclose(fp);
    }
    }else{
        printf("\n Error occured while creating or fetching file contents");
    }
}