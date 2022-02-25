/******************************************************************************
https://leetcode.com/problems/search-in-rotated-sorted-array/

2.18.2022
*******************************************************************************/

class Solution {
private:
    int findPivot(vector<int>& nums){
        int left = 0;
        int right = nums.size() -1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        
        int left = 0;
        int right = nums.size() -1;
        
        while (left <= right){
            int mid = left + (right - left) / 2;
            int midConverted = (mid + pivot) % nums.size();
            if (nums[midConverted] == target){
                return midConverted;
            }else if (nums[midConverted] < target){
                left = mid + 1;
            }else{
                right = mid -1;
            }
        }
        return -1;
    }
};