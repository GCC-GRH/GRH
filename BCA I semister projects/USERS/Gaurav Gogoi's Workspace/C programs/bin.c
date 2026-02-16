#include<stdio.h>

void main(){
    char data[50];
    FILE* fp=fopen("data.bin","wb");
    if(fp!=NULL){
        
            printf("\n Please enter your message: \n");
            gets(data);
           
        
        fwrite(&data,50,1,fp);
        fclose(fp);
    }else{
        printf("Error creating and loading the binary contents");
    }
}