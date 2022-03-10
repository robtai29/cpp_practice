/******************************************************************************
https://leetcode.com/problems/sort-array-by-parity/

10.29.2021
*******************************************************************************/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if (nums.size() <= 1){
            return nums;
        }
        int left = 0;
        int right = nums.size() -1;
        
        while (left < right){
            if (nums[left] % 2 == 0){
                left++;
            }
            
            if (nums[right] % 2 == 1){
                right--;
            }
            
            if (left < right && nums[left] % 2 == 1 && nums[right] %2 == 0){
                swap(nums[left], nums[right]);
                left++;
                right--;
            }

        }
         return nums;
    }
};