/******************************************************************************
https://leetcode.com/problems/binary-search/

10.31.21
*******************************************************************************/

class Solution {
public:
    //solution 1
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        int mid = (right - left)/2 + left;
        
        while (left <= right){
            mid = (right - left)/2 + left;
            int midVal = nums[mid];
            if (target > midVal){
                left = mid + 1;
            }else if (target < midVal){
                right = mid -1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};

//solution 2
/*
    int search(vector<int>& nums, int target) {
        auto ptr = lower_bound(nums.begin(), nums.end(), target);
        return ptr == nums.end() || *ptr != target ? -1 : distance(nums.begin(), ptr);
    }
*/