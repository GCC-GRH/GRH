#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    int arr1[]={1,2,3,4,5};
    int arr2[]={6,7,8,9,10};
    int arr1size=sizeof(arr1)/sizeof(arr1[0]);
    int arr2size=sizeof(arr2)/sizeof(arr2[0]);
    int* p=(int *)malloc((arr1size+arr2size)*sizeof(int));
    memcpy(p,arr1,sizeof(arr1));
    memcpy(p+(arr1size),arr2,sizeof(arr2));
    for(int i=0;i<(arr1size+arr2size);i++){
        printf("\n%d",p[i]);
    }
    free(p);
}