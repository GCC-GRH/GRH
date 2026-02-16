#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5
void main(){
    int arr1[N]={2,1,4,1,6},arr2[N]={5,1,3,5,7};
    int arr_size=(sizeof(arr1)+sizeof(arr2))/sizeof(int);
    int *res_array=(int *)malloc(arr_size*sizeof(int));
   memcpy(res_array,arr1,sizeof(arr1));
   memcpy(res_array+N,arr2,sizeof(arr2));
   for(int i=0;i<(N*2);i++){
    printf("%d ",res_array[i]);

   }

}