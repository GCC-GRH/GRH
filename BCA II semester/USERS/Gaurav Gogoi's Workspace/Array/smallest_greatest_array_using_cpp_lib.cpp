#include<iostream>
using namespace std;
int main(){
    int arr[]={5,15,22,1,-15,-24};
    int smallest=arr[sizeof(arr)/sizeof(int)-1];
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
    smallest=min(arr[i],smallest);
    }
    cout<<smallest;
}