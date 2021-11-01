/******************************************************************************
https://leetcode.com/problems/rotate-array/

10.31.2021
*******************************************************************************/

class Solution {

public:
    void rotate(vector<int>& nums, int k) {
       k = k % nums.size();
        int n = nums.size();
        reverse(nums.begin() + n -k, nums.end());
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin(), nums.end());
    }
};