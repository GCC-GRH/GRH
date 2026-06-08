#include<iostream>
using namespace std;

void bsort(int arr[], int arr_size){ // Array value passed through pass by referencing pointing-method
    int size = arr_size;
    int swap_variable;
    for(int i = 0; i < size -1;i++){
        for(int j = i+1; j < size;j++){
            if(arr[i] > arr[j]){
                swap_variable = arr[i];
                arr[i] = arr[j];
                arr[j] = swap_variable;
            }
        }
    }
}

int main(){
    int arr[] = {5,1,4,5,7,3};
    int arr_size = 6;
    bsort(arr, arr_size);
    for(int i = 0; i<=5; i++){
        cout<<arr[i]<<"\t";
    }
}