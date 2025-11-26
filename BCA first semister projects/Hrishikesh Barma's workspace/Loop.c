#include<stdio.h>
int main(){
    int i,a,count;
    printf("The prime number from 1 to 50 are:\n");
    for(i=2;i<=50;i++){
    count=1;//assume number is prime
    for(a=2;a<=i/2;a++){
        if(i%a==0){
            count=0;//assume number is not prime
            break;
        }
    }
    if(count==1){
        printf("%d ",i);
    }
    }
    return 0;
}