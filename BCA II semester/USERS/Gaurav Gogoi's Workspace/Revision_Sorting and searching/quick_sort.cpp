#include<iostream>
using namespace std;
int pivot(int arr[], int st, int end){
int idx = st - 1;
int pivot = end;
for(int j = st; j < end; j++){
    if(arr[j] <= arr[pivot]){
        idx++;
        swap(arr[j], arr[idx]);
    }

}
    idx++;
    swap(arr[end], arr[idx]);
    return pivot;
};

void quickSort(int arr[], int start, int end){
    if(start < end){
    int pvt = pivot(arr, start, end);
    quickSort(arr,start, pvt - 1); // Left quickSort call
    quickSort(arr,pvt+1,end); // Right quickSort call
    }
}


int main(){
    int arr[] = {5,2,4,3,1,6}; 
    int s = 6;
    quickSort(arr, 0, s-1);
    for(int i : arr){
        cout<<i<<endl;
    }
}