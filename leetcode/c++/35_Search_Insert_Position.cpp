/******************************************************************************
https://leetcode.com/problems/search-insert-position/

12.26.21
*******************************************************************************/

class Solution {
public:
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //use lower_bound which returns index of the first number that is equal or greater than the target
        int left = 0;
        int right = nums.size() -1;
        
        while (left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                return mid;
            }else if (nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        //based on loop condition, invariant is left == right in the end
        return nums[left] < target ? left + 1: left;
    }
};