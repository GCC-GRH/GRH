#include<stdio.h>
void main(){
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    int B[10]={1,2,3,4,5,6,7,8,9,10};
    int C[10];
    for(int i = 0; i<10; i++)
        C[i]=A[i] + B[i];

for(int i = 0; i<10; i++)
    printf("\n%d",C[i]);
}