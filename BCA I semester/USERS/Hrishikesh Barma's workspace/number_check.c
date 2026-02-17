#include<stdio.h>
int main(){
    int a;
    printf("enter any number:\n");
    scanf("%d",&a);
    if(a==0){
        printf("The number is zero\n");
    }else if(a%2==0){
        printf("The number is even\n");
    }else{
    printf("The number is odd");
    }
    return 0;
}