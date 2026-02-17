#include<stdio.h>
void main(){
    int i,j,k;
    char ch='a'-1;
    for(i=5;i>=1;i--){
        for(j=1;j<i;j++){
            printf(" ");
        }
        for(k=i;k<=5;k++){
            printf("%c ",ch+k);

        }
    printf("\n");
    }
}