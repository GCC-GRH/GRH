/*
    This program is to print the following pattern using nested for-loop operation.
    *
    **
    ***
    ****
    *****
    ******
*/
#include<stdio.h>
void main(){
for(int j=1;j<=6;j++){
    for(int i=1;i<=j;i++){
        printf("*");
    }
printf("\n");
}
}