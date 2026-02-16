#include<stdio.h>
void main(){
    int i,j;
    i=5;
    while(i>=1){
        j=i;
        while(j>=1){
            printf("%d ",j);
            j--;
        }
        printf("\n");
        i--;
    }
}