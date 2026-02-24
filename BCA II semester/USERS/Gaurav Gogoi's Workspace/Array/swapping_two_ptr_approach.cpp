#include<iostream>
using namespace std;
void swap(int arr[],int arr_size){
    int head_indexing=0;
    int tail_indexing=arr_size;
    int temp;
    while(head_indexing<tail_indexing){
        temp=arr[head_indexing];
        arr[head_indexing]=arr[tail_indexing];
        arr[tail_indexing]=temp;
        head_indexing++;
        tail_indexing--;
    }
}

int main(){
    int arr[]={4,9,5,1,6,3};
    swap(arr,sizeof(arr)/sizeof(int)-1);
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        cout<<arr[i]<<" ";
    }

}