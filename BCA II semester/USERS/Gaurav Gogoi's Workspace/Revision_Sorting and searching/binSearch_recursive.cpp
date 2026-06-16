#include<iostream>
#include<algorithm>
using namespace std;
bool binsearch_wrapper(int arr[], int target, int st, int end){
    int mid = st + (end - st)/2;
    if(st > end) return false;
    if(target == arr[mid]){
        return true;
    }

    if(target < arr[mid]) return binsearch_wrapper(arr,target,st, mid-1); // search left half
    if(target > arr[mid]) return binsearch_wrapper(arr,target,mid+1,end); // search right half
    return false;
}


void binarySearch(int* arr, int target){
    int *a = arr;
    int size = sizeof(a)/sizeof(a[0]) - 1;
    sort(a,a+size+1);
    if(binsearch_wrapper(a,target,0,size)){
        cout<<"Element found"<<endl;
    }else{
        cout<<"Element not found"<<endl;
    }
}

int main(){
    int arr[] = {5,2,4,3,1};   
    int target = 5;
    binarySearch(arr,target);
}
