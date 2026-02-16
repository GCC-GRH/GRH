#include<stdio.h>
#include<string.h>
void main(){
    int arr1[10]={1,2,3,4,5},arr2[]={6,7,8,9,10};
    int arr1size=5;
    memcpy(arr1+arr1size,arr2,sizeof(arr2));
    for(int i=0;i<10;i++){
        printf("\n%d",arr1[i]);
    }
}