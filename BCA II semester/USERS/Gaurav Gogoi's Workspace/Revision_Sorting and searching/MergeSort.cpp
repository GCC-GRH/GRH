#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    vector <int> temp;
    int i = start;
    int j = mid + 1;
    while(i<= mid && j<=end){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    // Copy remaining elements from left half
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    
    // Copy remaining elements from right half
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }
    
    // Copy all elements back to arr
    for(int k = 0; k < temp.size(); k++){
        arr[start + k] = temp[k];
    }
};

void mergeSort(int arr[], int start, int end){
    int mid = (start + end)/2;
    if(start < end){
    mergeSort(arr, start, mid); // Partitioning left half of the array
    mergeSort(arr, mid+1, end); // Partitioning the right half of the array
    merge(arr, start, mid, end);
    }
}



int main(){
    int arr[] = {5,2,4,3,1,6}; 
    int s = 6;
    mergeSort(arr, 0, s-1);
    for(int i : arr){
        cout<<i<<endl;
    }
}