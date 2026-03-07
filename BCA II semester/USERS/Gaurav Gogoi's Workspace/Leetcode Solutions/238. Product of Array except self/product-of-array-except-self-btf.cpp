#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> nums = {1,2,3,4};
    vector <int> ans;
    for(int i=0;i<nums.size();i++){
        int res=1;
        for(int j=0;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                res*=nums[j];
            }else{
                continue;
            }
        }
        ans.push_back(res);
    } 
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

// TLE leetcode
// Use of division operator is not allowed.