#include<stdio.h>
void main(){
    char data[50];
    FILE* fp=fopen("data.bin","rb");
    if(fp!=NULL){
        fread(&data,50,1,fp);
        printf("%s",data);
    }else{
        printf("\n Unable to read the binary file");
    }
}