#include<stdio.h>
void main(){
    FILE* fp=fopen("data.txt","r");
    int age;
    int height;
    fscanf(fp,"Age:%d\nHeight:%d",&age,&height);
    printf("Age:%d\nHeight:%d",age,height);
    fclose(fp);
}