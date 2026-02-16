#include<stdio.h>
int main(){
    int a,i,count=0;
    printf("Enter any number:\n");
    scanf("%d",&a);
    for(i=0;i<=a;i++){
        if(a%i==0){
            count++;
        }
    }
    if(count==2){
        printf("Prime number");
    }else{
        printf("Not a prime number");
    }
    return 0;
}