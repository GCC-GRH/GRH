#include<iostream>
using namespace std;

void merge(int arr[], int st,int mid, int end){
    int i = st, j = mid + 1;
    int temp[50];
    int idx = -1;

    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            idx++;
            temp[idx] = arr[i]; 
            i++;
        }else{
            idx++;
            temp[idx] = arr[j];
            j++;
        }
    }

    while(i<=mid){
        idx++;
        temp[idx] = arr[i];
        i++;
    }

    while(j<=end){
        idx++;
        temp[idx] = arr[j];
        j++;
    }
    int count = idx + 1;
    for(int i = 0; i<count; i++){
        arr[st + i] = temp[i];
    }
}
void mergeSort(int arr[], int st, int end){
    if(st>=end) return;
    int mid = st + (end - st)/2;
    mergeSort(arr, st, mid); // left call
    mergeSort(arr, mid + 1, end); // right call
    merge(arr, st, mid, end);
}

int main(){
    int arr[] = {5,2,4,3,1,6}; 
    int s = 6;
    mergeSort(arr, 0, s-1);
    for(int i : arr){
        cout<<i<<endl;
    }
}