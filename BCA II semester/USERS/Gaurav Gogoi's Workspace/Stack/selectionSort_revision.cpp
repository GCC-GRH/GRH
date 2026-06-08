#include<iostream>
using namespace std;    // {5,1,4,5,7,3}
void ssort(int arr[], int size){
    for(int i = 0; i<size-1;i++){
        int smallest = i;
        for(int j=i+1; j<size;j++){
            if(arr[j]<arr[smallest]){
                smallest = j;
            }
            swap(arr[i],arr[smallest]);
        }
    }
}


int main(){
    int arr[] = {5,1,4,5,7,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    ssort(arr,size);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<"\t";
    }
}