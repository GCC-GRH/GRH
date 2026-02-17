/*
    This program is to print the following pattern using nested for-loop operation.
    1
    12
    123
    1234
    12345
*/
#include<stdio.h>
void main(){
for(int j=1;j<=5;j++){
    for(int i=1;i<=j;i++){
        printf("%d",i);
    }
printf("\n");
}
}