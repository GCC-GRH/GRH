#include<stdio.h>
void main(){
    int num,factors=0;
    int i,j;
    printf("Please enter a value of N: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++){
        factors=0;
        for(j=1;j<=i;j++){
            if(i%j==0){
                factors++;
            }
        }
        if(factors==2){
            printf("\n%d",i);
        }
    }
}