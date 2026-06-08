#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

int findfirst(int arr[], int n,int target){
    int left = 0,right = n - 1, result = -1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(target == arr[mid]){
            result = mid;
            right = mid - 1;
        }else if(target < arr[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return result;
};

int findlast(int arr[], int n,int target){
    int left = 0,right = n - 1, result = -1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(target == arr[mid]){
            result = mid;
            left = mid + 1; // search for occurance right
        }else if(target < arr[mid]){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return result;
};

int main(){
    system("cls");
    int arr[] = {1,2,3,3,3,4,4,6,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr + size);
    int target;
    cout<<"Please enter a target to search within the array  :"<<endl;
    cin>>target;
    int first = findfirst(arr,size,target);
    int last = findlast(arr,size,target);
    if(first != -1){
        for(int i = first; i<=last;i++){
            cout<<"Target found at element idx" <<i <<endl;
        }
    }else{
        cout<<"Target element not present within the array";
    }

}