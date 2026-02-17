#include<stdio.h>
void main(){
    int arr[5]={2,3,1,2,3};
    int max=arr[0];
    for(int i=0;i<5;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    printf("\n The maximum array element is %d",max);
}