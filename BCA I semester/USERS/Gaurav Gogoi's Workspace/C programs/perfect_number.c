#include<stdio.h>
void main(){
    int n,sum=0;
    printf("\n Please enter a number : ");
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    if(sum==n){
        printf("\n It is a perfect number");
    }
}