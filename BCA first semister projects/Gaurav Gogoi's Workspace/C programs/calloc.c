#include<stdio.h>
#include<stdlib.h>
void main(){
    int *ptr;
    ptr=(int *)calloc(10,sizeof(int));
    free(ptr);
    for(int i=0;i<10;i++){
        printf("\nThe uninitialised value obtained from Array using dynamic mem alloc is %d for element %d",ptr[i],i);
    }
}

// calloc is same as that of malloc, but instead of initialising the array or variable element with non or garbage value...it simply initilisess with 0