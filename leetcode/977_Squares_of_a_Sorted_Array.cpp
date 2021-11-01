/******************************************************************************
https://leetcode.com/problems/squares-of-a-sorted-array/

10.31.2021
*******************************************************************************/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        
        int left = 0;
        int right = nums.size() -1;
        
        for (int i = res.size() -1; i >= 0; i--){
            if (abs(nums[left]) >= abs(nums[right])){
                res[i] = nums[left] * nums[left];
                left++;
            }else{
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
            return res;
    }
};