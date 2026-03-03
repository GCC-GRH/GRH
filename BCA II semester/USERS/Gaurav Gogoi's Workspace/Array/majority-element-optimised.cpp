#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector <int> arr={2,2,1,1,1};
    sort(arr.begin(),arr.end());
    int frequency=1, ans=arr[0];
    int i=1,n=arr.size();
    while(i < n){
        if(arr[i]==ans){
            frequency++;
        }else{
            
            frequency = 1; ans = arr[i];
        }
        if(frequency>(n/2)){
            cout<<i<<" is the majorly occuring element"<<endl;
            break;
        }
    i++;
}
    if(frequency<n/2){
        cout<<"No majority element found within the vector array"<<endl;
    }
}

// time complexity O(nlogn)