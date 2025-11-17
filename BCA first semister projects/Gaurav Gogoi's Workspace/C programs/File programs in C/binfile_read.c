#include<stdio.h>
void main(){
    int num;
    FILE* fp=fopen("bin.dat","rb");
    if(fp==NULL){
        printf("Error fetching binary data");
    }{
        fread(&num,sizeof(num),1,fp);
        printf("%d",num);
        fclose(fp);
    }
}