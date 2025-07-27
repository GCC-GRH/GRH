#include<stdio.h>
void main(){
int i,j;
for(i=5;i>=1;i--){
    

    for(int k=5;k>i;k--){
        printf(" ");
    }
    
    
    
    for(j = i; j >=1 ; j--)
    {
        printf("%d",j);
    }
    printf("\n");
}   
}