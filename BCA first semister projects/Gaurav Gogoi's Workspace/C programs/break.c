// This program fascillates us use of break statement within a loop
#include<stdio.h>
void main(){
    int i;
    for(i=1;i<=10;i++){
        if(i==5){
            break;
        }
        printf("\n %d",i);
    }
}