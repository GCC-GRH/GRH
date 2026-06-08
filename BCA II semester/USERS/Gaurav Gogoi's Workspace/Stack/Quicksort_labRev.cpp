#include<iostream>
using namespace std;
int partition(int arr[],int start,int end){
    int idx = start - 1;
    int pivot = arr[end];
    for(int i = start; i<end; i++){
        if(arr[i]<=pivot){
            idx++;
            swap(arr[i],arr[idx]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
};


void quicksort(int arr[],int start, int end){
    if(start < end){
    int pivot = partition(arr, start, end);
    quicksort(arr,start,pivot - 1);
    quicksort(arr, pivot +1, end);
    }
};


int main(){
    int arr[] = {2,3,1,6,8,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0, size - 1);
    for(int i : arr){
        cout<<i<<"\t";
    }
}