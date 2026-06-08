#include<iostream>
using namespace std;
void bsort(int arr[], int n){
    int temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
};

int main(){
    int arr[] = {2,3,1,6,8,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    bsort(arr,size);
    for(int i : arr){
        cout<<i<<"\t";
    }
}