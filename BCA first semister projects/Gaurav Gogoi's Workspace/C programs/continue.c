// This program fascillates us use of continue statement within a loop
#include<stdio.h>
void main(){
    int i;
    for(i=1;i<=10;i++){
        if(i==5){
            continue;
        }
        printf("\n %d",i);
    }
}