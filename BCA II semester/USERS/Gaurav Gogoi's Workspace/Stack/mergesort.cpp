#include<iostream>
using namespace std; //{5,1,4,5,7,3}

void merge(int arr[], int start,int mid, int end){
    int temp[50];
    int i = start; //left part
    int j = mid + 1; // right part
    int k = 0;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
         temp[k] = arr[i];
         k++;
         i++;
    }
    while(j<=end){
        temp[k] = arr[j];
            k++;
            j++;
    }
    for(int idx = 0; idx < (sizeof(temp)/sizeof(temp[0]));idx++){
        arr[idx + start] = temp[idx];
    }
}
void mergeSort(int arr[], int start, int end){
    if(start < end){
        
        int mid = start + (end-start)/2;
        mergeSort(arr,start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr,start,mid,end);
    }
}

int main(){
    int arr[] = {5,1,4,5,7,3};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,arrSize-1);
    for(int i : arr){
        cout<<i<<"\t";
    }
}