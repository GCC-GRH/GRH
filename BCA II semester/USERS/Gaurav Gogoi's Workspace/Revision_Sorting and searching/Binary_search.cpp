#include<iostream>
#include<algorithm>
using namespace std;

bool binSearch(int *arr, int target){
    int *a = arr;
    int size = sizeof(a)/sizeof(a[0]);
    sort(a, a + size);
    int start = 0, end = size - 1;
    while(start <= end){
        int mid = (start + end)/2;
        if(target == arr[mid]){
            return true;
        }
        if(target < arr[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return false;
}


int main(){
    int arr[] = {5,2,4,3,1};   
    int target = 5;
    if(!binSearch(arr, target)){
        cout<<"Target not found with the array"<<endl;
    }else{
        cout<<"Target found within the given array"<<endl;
    }
}
