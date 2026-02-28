#include<iostream>
using namespace std;
int main(){
    int arr[]={2,7,11,15};
    int targ=13;
    int n=sizeof(arr)/sizeof(arr[0]),i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]+arr[j]==targ){
                cout<<"("<<arr[i]<<","<<arr[j]<<")";
            }
        }
        cout<<endl;
    }
}