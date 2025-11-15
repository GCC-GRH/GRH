#include<stdio.h>
void main(){
    char a[40],b[40];
    int len=0;
    printf("\n Please enter a string : ");
    gets(a);
    while(a[len]!='\0')
        len++;
    for(int i=0;i<len;i++){
        if(a[i]>='A' && a[i]<='Z'){
            b[i]=a[i]+32;
        }else{
            if(a[i]>='a' && a[i]<='z'){
                b[i]=a[i]-32;
            }else{
                b[i]=a[i];
            }
        }
    }
    b[len]='\0';
    printf("\n Toggeled string : %s",b);
    
}