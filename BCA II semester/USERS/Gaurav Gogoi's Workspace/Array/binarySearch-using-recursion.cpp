#include<iostream>
#include<algorithm>
using namespace std;
int binarySearch(int target, int* arr, int st, int end){
    if(st<=end){
    int mid = st + (end - st)/2;
    if(target==arr[mid]){
        return mid;
    }else if(target < arr[mid]){
        return binarySearch(target, arr, st, mid - 1);
    }else if(target > arr[mid]){
        return binarySearch(target, arr, mid + 1, end);
    }
}else{
    return -1;
}

};

int main(){
    int arr[] = {2,1,8,4,5};
    int targ;
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + n); // O(nlogn)
    cout<<"Enter a target to search: ";
    cin>>targ;
    int result = binarySearch(targ, arr, 0, n-1); // O(logn)
    (result != -1) ? cout<<"Idx element found at "<<result : cout<<"Element not found";
    cout<<endl;
}
// 2,1,8,4,5 ---> 1,2,4,5,8