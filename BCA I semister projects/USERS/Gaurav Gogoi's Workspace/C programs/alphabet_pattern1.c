#include<stdio.h>
void main(){
    int i,j,k;
    char x='a'-1;
    int a;
    for(i=5;i>=1;i--)
    {
        for(j=1;j<i;j++){
            printf(" ");
        }
        a=1;
        for(k=5;k>=i;k--){
           
            printf("%c", x+a);
            a+=1;
        }
        printf("\n");
    }
}