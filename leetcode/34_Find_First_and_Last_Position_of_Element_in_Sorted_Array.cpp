/******************************************************************************
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

11.27.2021
*******************************************************************************/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return {-1, -1};
        }
        int low = 0;
        int high = nums.size() -1;
        vector<int> res(2, -1);
        
        while (low < high){
            int mid = low + (high - low) / 2;
            if (target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        
        if (nums[low] != target){
            return res;
        }else{
            res[0] = low;
        }
        
        target += 1;
        high = nums.size() -1;
         while (low < high){
            int mid = low + (high - low) / 2;
            if (target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        
        res[1] = nums[low] == target -1 ? low : low -1;
        return res;
    }
};