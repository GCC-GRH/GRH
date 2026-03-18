#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,4,6,5}; //sorted array;
    int n = sizeof(arr)/sizeof(arr[0]); 
    for(int i = 0; i < n-1; i++){
            bool isSwap = false; 
            for(int j = i+1; j < n; j++){
                if(arr[i] < arr[j]){
                    swap(arr[i],arr[j]);
                    isSwap = true;
                }
            }
    
            if(!isSwap){
                cout<<"Array already sorted"<<endl;
            }
    
    
        }
}