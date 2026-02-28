#include<iostream>
using namespace std;
int main(){
    int arr[]={3,-4,5,4,-1,7,-8};
    int max=arr[0],curSum=0;
    for(int i : arr){
        curSum+=i;
        if(curSum>max){
            max=curSum;
        }
        if(curSum<0){curSum=0;};

    }
    cout<<max;

}