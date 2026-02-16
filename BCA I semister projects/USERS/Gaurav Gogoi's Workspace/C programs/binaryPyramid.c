#include<stdio.h>
void main(){
    int i,j;
    for(i=1;i<=5;i++){
        for(int k=5;k>=i;k--){
            printf(" ");
        }
        
        
        
        
        
        for(j=1;j<=i;j++){
            if(i%2==0 && j%2!=0){
                printf("1 ");
            }else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}