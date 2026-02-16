#include<stdio.h>
void main(){
    char content[50];
    FILE* fp=fopen("username.txt","r");
    if(fp==NULL){
        printf("Failed to access file contents");
    }else{
        fgets(content,50,fp);
    }
    printf("%s",content);
    fclose(fp);
}
