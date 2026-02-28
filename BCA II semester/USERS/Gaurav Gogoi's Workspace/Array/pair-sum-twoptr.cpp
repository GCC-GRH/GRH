#include<iostream>
using namespace std;
int main(){ 
    int arr[]={2,7,11,15};
    int target=9;
    //Declaring the two variables to point to the head and last end of the array data element
    int i=0,j=sizeof(arr)/sizeof(arr[0])-1;
    while(i<j){
        if(arr[i]+arr[j]<target){
            i++;
        }else if(arr[j]+arr[i]>target){
            j--;
        }else if(arr[j]+arr[i]==target){
            cout<<"Target found at : ";
            cout<<"("<<arr[i]<<","<<arr[j]<<")";
            break;
        }
    }
}