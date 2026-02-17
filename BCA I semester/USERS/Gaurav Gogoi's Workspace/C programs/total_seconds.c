#include<stdio.h>
int main(){
    int ts,h, m, s;
    printf("\n Please enter your total seconds : ");
    scanf("%d",&ts);
    h=ts/3600;
    ts=ts%3600;
    m=ts/60;
    s=ts%60;
        printf("\n The following is the evaluated result ==> \n Hours left : %d \n Minutes left  : %d \n Seconds left : %d \n ",h, m, s);
        
        return 0;
}