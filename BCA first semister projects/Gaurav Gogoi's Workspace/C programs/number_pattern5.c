#include<stdio.h>
void main(){
    int i,j;
    for(j=1;j<=5;j++){
    for(i=5;i>=j;i--){
        printf("%d",i);
    }
    printf("\n");
}
}