#include<iostream>

bool linearSearch(int *arr, int target){
    int *n = arr;
    int size  = sizeof(n)/sizeof(n[0]);
    for(int i = 0; i<size; i++){
        if(target == n[i]) return true;
    }
    return false;
}

int main(){
    int arr[] = {5,2,4,3,1};
    bool res = linearSearch(arr,5);
    if(!res){
        std::cout<<"Element not found"<<std::endl;
    }else{
        std::cout<<"Element found"<<std::endl;
     
    }
}