/******************************************************************************
https://leetcode.com/problems/house-robber/

9.9.2021, 1.1.22, 2.13.22
*******************************************************************************/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() ==1){
            return nums[0];
        }
        vector<int> memo(nums.size(), -1);
        memo[0] = nums[0];
        memo[1] = max(nums[0], nums[1]);
        return rob(nums.size()-1, memo, nums);
    }
private:
    int rob(int i, vector<int>& memo, vector<int>& nums){
        if (i < 0){
            return i;
        }
        
        if (memo[i] == -1){
            memo[i] = max(rob(i-1, memo, nums), rob(i-2, memo, nums) + nums[i]);
        }
        
        return memo[i];
    }
    
};
/*

//recurence relation: loot(i) = max(loot[i-2] + nums[i], loot[i]);
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1){
            return nums[0];
        }
    
        vector<int> loot(nums.size());
        loot[0] = nums[0];
        loot[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++){
            loot[i] = max(loot[i-2] + nums[i], loot[i-1]);
        }

        return loot[n-1];
    }
};
*/