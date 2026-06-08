#include<iostream>
using namespace std;
void isort(int arr[],int size){
    int current, prev;
    for(int i = 1; i<size; i++){
        current = arr[i];
        prev = i - 1;
        while(prev >= 0 && arr[prev] > current){
            arr[prev + 1] = arr[prev];
            prev --;
        }
        arr[prev + 1] = current;

    }
}


int main(){
    int arr[] = {5,1,4,5,7,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    isort(arr,size);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}