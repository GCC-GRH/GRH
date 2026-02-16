#include<stdio.h>
int main(){
    int i,sum;
    sum=0;
    i=2;
    while(i<=100){
        sum=sum+i;
        i=i+2;
        printf("the sum of all the even no. is %d\n",sum);
    }
    return 0;
}