#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int arr1[] = {6,1,2,3,2};
    int arr2[] = {9,1,3,2,7};
    int size = (sizeof(arr1)/sizeof(arr1[0]) ) + (sizeof(arr2)/sizeof(arr2[0]));
    int merged[size];
    memcpy(merged,arr1,sizeof(arr1));
    memcpy(merged + sizeof(arr1)/sizeof(arr1[0]),arr2,sizeof(arr2));


    for(int i : merged){
        cout<<i<<"\t";
    }
}