/******************************************************************************
https://leetcode.com/problems/house-robber/

9.9.2021
*******************************************************************************/

class Solution {
public:
    //recursive relationship: rob(i) = max(rob(i-2) + currenthouse, rob(i-1))
    
    int rob(vector<int>& nums, vector<int>& m, int i){
        if (i < 0){
            return 0;
        }
        
        if (m[i] == INT_MIN){
            
            m[i] = max(rob(nums, m, i-2) + nums[i], rob(nums, m, i-1));
        }
        return m[i];   
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), INT_MIN);
        memo[0] = nums[0];
        
        return rob(nums, memo, nums.size()-1);
    }
};

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        
        memo[0] = nums[0];
        if (memo.size() > 1){
            memo[1] = max(nums[0], nums[1]);
        }
        
        for (int i = 2; i < memo.size(); i++){

            memo[i] = max(memo[i-2] + nums[i], memo[i-1]);
        }
        
        return memo[memo.size()-1];
    }
};
*/