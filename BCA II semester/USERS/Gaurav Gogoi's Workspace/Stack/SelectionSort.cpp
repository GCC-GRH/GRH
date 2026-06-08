#include<iostream>
using namespace std;
void ssort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int smallest = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j]<arr[smallest]){
                smallest = j;
            }

        }
        swap(arr[i],arr[smallest]);
    }
}

int main(){
    int arr[] = {2,3,1,6,8,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    ssort(arr,size);
    for(int i : arr){
        cout<<i<<"\t";
    }
}