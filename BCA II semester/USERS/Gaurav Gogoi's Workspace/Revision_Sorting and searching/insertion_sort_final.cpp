#include<iostream>
using namespace std;
void isort(int arr[], int size){
    for(int i = 1; i<size; i++){
        int current = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev] > current){
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = current;
    }

}



int main(){
    int arr[] = {5,2,4,3,1}; //2,5,4,3,1 .. 2,4,5,3,1
    int s = 5;
    isort(arr,5);
    for(int i : arr){
        cout<<i<<endl;
    }
}