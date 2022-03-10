/******************************************************************************
https://leetcode.com/problems/monotonic-array/

7.23.2021
*******************************************************************************/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
     
        bool increasing = true;
        bool decreasing = true;
        
        for (int i = 1; i < nums.size(); i++){
            
            increasing = increasing & (nums[i] >= nums[i-1]);
            decreasing = decreasing & (nums[i] <= nums[i-1]);
            
        }
        
        return decreasing || increasing;
    }
};