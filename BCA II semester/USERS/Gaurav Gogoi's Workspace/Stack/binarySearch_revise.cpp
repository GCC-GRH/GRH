#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int mid;
    int st = 0; 
    int arr[] = {3,1,4,6,8,3,7,3,2,4};
    int flag = 0;
    int size = sizeof(arr)/sizeof(arr[0]) - 1;
    sort(arr,arr + size+1);
    int end = size;
    int target;
    cout<<"Please enter a target value : ";
    cin>>target;
    while(st <= end){
        mid = st+ (end-st)/2;
        if(target == arr[mid]){
            cout<<"Target found at idx "<<mid<<endl;
            flag = 1;
            break;
        }else if(target<arr[mid]){
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    if(flag==0){
        cout<<"Target element not exist within the array";
    }

}