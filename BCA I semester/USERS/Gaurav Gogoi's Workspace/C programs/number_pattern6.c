#include<stdio.h>
void main(){
    int i;
    for(i=1;i<=5;i++){
        for(int k=1;k<i;k++){
            printf(" ");
        }
        for(int j=i;j<=5;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    printf("\n");
}