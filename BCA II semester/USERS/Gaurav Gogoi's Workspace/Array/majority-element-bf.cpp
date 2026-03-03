#include<iostream>
using namespace std;
int main(){
    int arr[]={1,1,2,2,2,2};
    int elements=sizeof(arr)/sizeof(arr[0]);
    int major;
    bool found=false;
    for(int i : arr){
        int cnt=0;
        for(int j : arr){
            if(i==j){
                cnt++;
            }

        }
        if(cnt>elements/2){
            major=i;
            found=true;

        }
    }
    if(found==true){
    cout<<major<<" occurs in majority times";
    }else{
        cout<<"No majority occuring data element";
    }
}
// Time Complexity = O(n²)