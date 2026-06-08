#include<iostream>
using namespace std;
int main(){
    int arr[] = {3,2,7,5,9,10,65,32};
    int target;
    int i=0; // Loop iterator
    int flag = 0;

    cout<<"Please enter the element you'd like to search :"<<endl;
    cin>>target;
    while(i < sizeof(arr)){
        if(target==arr[i]){
            cout<<"Element found at idx : "<<i<<endl;
            flag=1;
            break;

        }
        i++;
    }
    if(flag==0) cout<<"Element not found!"; 
}