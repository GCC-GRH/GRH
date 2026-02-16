#include<stdio.h>
void largest(int* arr,int N){
    int num=arr[0];
    for(int i=0;i<N;i++){
        if (num<arr[i])
        {
            num=arr[i];
        }
        
    }
    printf("%d is the largest element",num);
};
void main(){
    int arr[5]={2,3,4,6,8};
    largest(arr,5);
}