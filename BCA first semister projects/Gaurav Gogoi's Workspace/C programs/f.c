#include<stdio.h>
void main(){
    FILE* fp=fopen("data.txt","w");
    int age=98;
    int height=6;
    fprintf(fp,"Age:%d\nHeight:%d",age,height);
    fclose(fp);
}