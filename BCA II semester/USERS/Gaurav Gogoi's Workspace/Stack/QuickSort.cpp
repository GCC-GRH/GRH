#include<iostream>
using namespace std;


int partition(int arr[], int start, int end){
    int idx = start - 1;
    int pivot = arr[end];
    for(int j = start; j<end;j++){
        if(arr[j] < pivot){
            idx++;
            swap(arr[idx],arr[j]);

        }
    }
    idx++;
    swap(arr[end],arr[idx]);
    return idx;
};

void qsort(int arr[], int start, int end){
    if(start < end){
        int pivot = partition(arr,start,end);
        qsort(arr,start,pivot - 1); // Left sort
        qsort(arr,pivot + 1, end); // Right sort

};
}

int main(){
    int arr[] = {5,1,4,5,7,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    qsort(arr,0,size);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}
