#include<iostream>
using namespace std;
int main(){
    int arr[] = {4,1,5,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i,j;
    for(i=0;i<n-1;i++){
        int smallest = i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[smallest]){
                smallest=j;
            }
        }
        swap(arr[i],arr[smallest]);
    }
}
