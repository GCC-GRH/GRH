#include<stdio.h>
#include<string.h>
void ispalin(char* str){
    char *a=str;
    int i,j, size=strlen(a);
    for(i=0,j=size-1;j!=0;i++,j--){
        if(a[i]!=a[j]){
            printf("\n Not a palindrome string");
            break;
        }else{
            printf("\n It is a palindrome string");
            break;
        }
    }

};

void main(){
    char txt[20]="NAYAN";
    ispalin(txt);
}