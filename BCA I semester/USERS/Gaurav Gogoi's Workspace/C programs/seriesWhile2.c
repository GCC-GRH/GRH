#include<stdio.h>
void main(){
    int i=1, j=10;
    int opt=0;
    while(i<=10){
        printf("%d ",i);
        printf("%d ",j - opt);
        i++;
        opt++;
    }
}