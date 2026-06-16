#include<iostream>
using namespace std;
void selectSort(int arr[], int size){
    for(int i = 0; i<size-1;i++){
        int smallest = i;
        for(int j = i+1; j<size;j++){
            if(arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        swap(arr[i], arr[smallest]);
    }
}