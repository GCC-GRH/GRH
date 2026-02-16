#include<stdio.h>
void main(){
    int i,j,k;
    for(i=1;i<=15;i++){
        for(k=1;k<=i;k++){
            printf(" ");
        }
        for(j=15;j>i;j--){
            printf("* ");
        }
        printf("\n");
    }
}