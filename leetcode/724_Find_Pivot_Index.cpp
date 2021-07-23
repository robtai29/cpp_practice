/******************************************************************************
https://leetcode.com/problems/find-pivot-index/

7.23.21
*******************************************************************************/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left{0};
        int right = accumulate(begin(nums), end(nums), 0);
        
        for (int i = 0; i < nums.size(); i++){
            
            right -= nums[i];
            if (left == right){
            
                return i;
            }
            
            left += nums[i];
        }
        return -1;
    }
};