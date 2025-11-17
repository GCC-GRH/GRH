#include<stdio.h>
void main(){
    FILE* fp;
    fp=fopen("username.txt","r");
    if(fp==NULL){
        printf("Failed to open the file");
    }else{
        printf("File accessed successfully");
    }
}