#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> nums={1,2,2,1,1,3};
    int frequency=0;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        if(frequency==0){
            ans=nums[i];
        }
        if(nums[i]==ans){
            frequency++;
        }else{
            frequency--;
        }
    }
    cout<<ans<<endl;
}