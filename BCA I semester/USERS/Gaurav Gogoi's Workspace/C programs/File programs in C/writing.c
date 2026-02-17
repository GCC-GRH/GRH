#include<stdio.h>
void main(){
    char str[50];
    FILE* fp=fopen("username.txt","w");
    if(fp==NULL){
        printf("\n Error creating or reading the file contents");
    }else{
        printf("Please enter your contents : \n==> ");
        gets(str);
        fputs(str,fp);
        fclose(fp);
    }
}