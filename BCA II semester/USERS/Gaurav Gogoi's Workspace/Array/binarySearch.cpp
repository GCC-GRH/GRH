#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[] = {2,1,8,4,5}; // sorted version : {1,2,4,5,8}
    sort(arr,arr + sizeof(arr)/sizeof(arr[0]));
    int mid = (sizeof(arr)/sizeof(arr[0])-1)/2;  
    int head = 0, tail = sizeof(arr)/sizeof(arr[0])-1;
    int target;
    cout<<"Enter a target value: ";
    cin>>target;
    cout<<endl;
    while(head <= tail){
        if(target == arr[mid]){
            cout<<"Element found at idx: "<<mid;
            break;
        }else if(target < arr[mid]){
            tail = mid - 1;
        }else if(target > arr[mid]){
            head = mid + 1;
        }
        mid = head + (tail - head)/2; 
    }
    if(target != arr[mid]){
    cout<<"Target element not found!";
    }
}

// Binary search can only be applied on sorted array. 
// Time-complexity : O(logn)