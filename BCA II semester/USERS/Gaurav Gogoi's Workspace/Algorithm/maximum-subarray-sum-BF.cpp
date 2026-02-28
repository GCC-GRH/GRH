#include<iostream>
#include<vector>
using namespace std;
// Maximum subarray sum using bruteforce technique
int main(){
    int n=5;
    int arr[5]={1,2,3,4,5};
    int maxSum=0;
    for(int st=0;st<n;st++){
        int currSum = 0;
        for(int end=st;end<n;end++){
            currSum+=arr[end];
            if(currSum>maxSum){
                maxSum=currSum;
            }
        }
    } 
    cout<<"The maximum subarray sum is "<<maxSum;
}