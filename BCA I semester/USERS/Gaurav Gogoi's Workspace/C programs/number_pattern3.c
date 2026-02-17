/*
    This program is to print the following pattern using nested for-loop operation.
    54321
    5432
    543
    54
    5
*/
#include<stdio.h>
void main(){
for(int j=1;j<=5;j++){
    for(int i=5;i>=j;i--){
        printf("%d",i);
    }
printf("\n");
}
}