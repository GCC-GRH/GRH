#include<stdio.h>
int sum(int n){
    if(n==1){
        return 1;
    }else{
        return n+sum(n-1);
    };
}

void main(){
    printf("Sum of 5 as N is %d",sum(5));
}