#include<stdio.h>
void main(){
    int i=0;
    printf("\n Would you like to invoke the backward goto statement? Enter 1 for and 0 for no: ");
    scanf("%d",&i);
    invoked:
    printf("\n Hello world");

    if(i==1){
     i=0;
     goto invoked;
    }
}