#include<stdio.h>
void findlargest(int* arr, int n){
    int *a=arr;
    int max;
    int temp=a[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    printf("\nMax value is %d",max);
};

void main(){
    int arr[]={4,1,2,5,6,2};
    findlargest(arr,6);
}