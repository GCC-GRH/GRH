#include<stdio.h>

void bubbleSort(int arr[]);
void main(){
    int arr[5]={5,2,3,1,2};
    bubbleSort(arr);

}
void bubbleSort(int arr[]){
    int temp;
    int n=4;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int k=0;k<=n;k++)
        printf("%d ",arr[k]);
}

