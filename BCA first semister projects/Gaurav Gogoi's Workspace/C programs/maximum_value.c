#include<stdio.h>
void main(){
    int value[10];
    int n,maximum=0;
    int pos;
    printf("\n How many indices would you like to reserve ? \n==>");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\n Please enter a value for the %dth position \n==>",i);
        scanf("%d",&value[i]);
        if(value[i]>maximum){
            maximum=value[i];
            pos=i;
        }
    }
    printf("\n The maximum value of array is %d at position %d",maximum,pos);
}