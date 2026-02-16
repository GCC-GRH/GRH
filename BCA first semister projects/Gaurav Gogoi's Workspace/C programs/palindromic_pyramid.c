#include<stdio.h>
#define N 5
void main(){
    int i,j,k,l;
    for(i=1;i<=N;i++){
        for(j=1;j<=N-i;j++){
            printf("  ");
        }
        // increasing palindroming number
        for(k=i;k<=2*i-1;k++){
            printf("%d ",k);
        }

        //Decresing palindromic nnumber

        for(k=2*i-2;k>=i;k--){
            printf("%d ",k);
        }




        printf("\n");
    }
}