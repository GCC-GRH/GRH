#include<iostream>
using namespace std;
void bSort(int* arr, int s){
    int *a = arr;
    int temp;
    int size = s;
    for(int i = 0; i<size - 1;i++){
        for(int j = i+1; j<size;j++){
            if(a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            
        }
    }
    
}

int main(){
    int arr[] = {5,2,4,3,1};
    int s = 5;
    bSort(arr,5);
    for(int i : arr){
        cout<<i<<endl;
    }
}