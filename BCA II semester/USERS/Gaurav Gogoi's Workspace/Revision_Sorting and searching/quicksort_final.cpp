#include<iostream>
using namespace std;

int pivot(int arr[], int st, int end){
    int pivot = arr[end];
    int idx = st - 1;
    for(int i = st; i<end; i++){
        if(arr[i] <= pivot){
            idx++;
            swap(arr[i], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}


void quicksort(int arr[], int st, int end){
    if(st < end){    
    int pivt = pivot(arr, st, end);
    quicksort(arr, st, pivt - 1); // left call
    quicksort(arr,pivt + 1, end); // Right call
    }
}