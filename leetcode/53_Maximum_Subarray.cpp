/******************************************************************************
https://leetcode.com/problems/maximum-subarray/

7.5.2021
*******************************************************************************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local_max = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < nums.size(); i++){
            
            local_max = max(nums[i], local_max + nums[i]);
            result = max(local_max, result);
        }
    
        return result;
    }
};