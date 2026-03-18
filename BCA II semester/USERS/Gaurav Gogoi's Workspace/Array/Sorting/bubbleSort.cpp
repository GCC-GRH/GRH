#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,1,8,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp;
    for(int i = 0;i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
}
 for(int i=0;i<n;i++){
            cout<<arr[i]<<endl;
        }
}