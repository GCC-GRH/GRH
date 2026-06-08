#include<iostream>
using namespace std;
void isort(int arr[], int size){
    int key, j;
    for(int i = 1; i<= size - 1;i++){
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
};

int main(){
    int arr[] = {2,3,1,6,8,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    isort(arr,size);
    for(int i : arr){
        cout<<i<<"\t";
    }
}