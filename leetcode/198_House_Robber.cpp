/******************************************************************************
https://leetcode.com/problems/house-robber/

9.9.2021, 1/1/22
*******************************************************************************/

class Solution {
public:
    //recursive relationship: rob(i) = max(rob(i-2) + currenthouse, rob(i-1))
    //top down
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
    //bottom up
    int rob(vector<int>& nums) {
        //each cell represents the maximum money from beginning to ith element, or local max thus far
        vector<int> memo(nums.size(), 0);
        
        memo[0] = nums[0];
        if (nums.size() > 1){
            memo[1] = max(nums[0], nums[1]);
        }
        
        for (int i = 2; i < nums.size(); i++){
            memo[i] = max(memo[i-1], memo[i-2] + nums[i]);   
        }
        
        return memo[nums.size()-1];
    }
};
*/