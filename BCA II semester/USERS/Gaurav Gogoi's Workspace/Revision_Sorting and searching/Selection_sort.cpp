#include<iostream>
using namespace std;
void isort(int* arr, int size){
    int *a = arr;
    
    for(int i = 0; i<size-1; i++){
    int smallest = i;
        for(int j = i+1; j<size; j++ ){
            if(a[j]<a[smallest]){
                smallest = j;
            }
        }
        swap(a[i],a[smallest]);
    }
}

int main(){
    int arr[] = {5,2,4,3,1};
    int s = 5;
    isort(arr,5);
    for(int i : arr){
        cout<<i<<endl;
    }
}