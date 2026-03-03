class Solution {
public:
    int majorityElement(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int frequency=1, ans=nums[0];
    int i=1,n=nums.size();
    while(i < n){
        if(nums[i]==ans){
            frequency++;
        }else{
            
            frequency = 1; ans = nums[i];
        }
        if(frequency>(n/2)){
            return ans;
        }
        i++;
        }
        return ans;
    
    }
    
};