/******************************************************************************
https://leetcode.com/problems/house-robber-ii/

9.9.2021
*******************************************************************************/
class Solution {
public:
    
    int rob(vector<int>& num, int left, int right){
        int size = right - left + 1;
        vector<int> v(size, 0);
        v[0] = num[left];
        v[1] = max(num[left], num[left+1]);
        
        for (int i = 2; i < size; i++){
            int currentVal = num[i + left];
            
            v[i] = max(v[i-2] + currentVal, v[i-1]);    
        }
        return v[size-1];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        
        if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }
                
        int size = nums.size();
        
        return max(rob(nums, 0, size-2), rob(nums, 1, size-1));
    }
};