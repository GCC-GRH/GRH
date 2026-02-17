#include<stdio.h>
void main(){
    int number;
    FILE* fp=fopen("bin.dat","wb");
    if(fp==NULL){
        printf("Error creating the file");
    }
        number=32;
        fwrite(&number,sizeof(number),1,fp);
        fclose(fp);
    
}