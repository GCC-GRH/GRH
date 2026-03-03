class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int elements=nums.size();
    for(int i : nums){
        int cnt=0;
        for(int j : nums){
            if(i==j){
                cnt++;
            }

        }
        if(cnt>elements/2){
           return i;

        }
           
        
    }
        return -1;
    }
    
};