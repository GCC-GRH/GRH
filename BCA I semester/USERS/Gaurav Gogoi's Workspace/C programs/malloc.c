#include<stdio.h>
#include<stdlib.h> //Dynamic Memory allocation funtion definitions belongs to this header file module
void main(){
    int *ptr;
    ptr= (int *)malloc(3*sizeof(int));
    for(int i=0;i<3;i++){
    printf("Please enter a value for element %d",i);
    scanf("%d",&ptr[i]);
    }
    for(int i=0;i<3;i++){
    printf("\nValue for element %d is %d",i,ptr[i]);
    }
}