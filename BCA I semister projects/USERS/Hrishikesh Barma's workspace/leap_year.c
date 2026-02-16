#include<stdio.h>
int main(){
    int x;
    printf("Enter a year:\n");
    scanf("%d",&x);
    if(x%4==0||x%100!=0 && x%400==0){
        printf("Leap year");
    }else {
        printf("Not a leap year");
    }
    return 0;
    }
