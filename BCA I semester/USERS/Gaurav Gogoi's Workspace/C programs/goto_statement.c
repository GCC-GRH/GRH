#include<stdio.h>
void main(){
    int i=1;
    if(i==0){
        goto ALTERNATE;
    }
    printf("\n This code is executed without the use of goto statement");

    ALTERNATE:
    printf("\n Hello World");

}