/******************************************************************************
https://leetcode.com/problems/rotate-array/
12.26.2021
*******************************************************************************/

class Solution {

public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.end() -k, nums.end());
        reverse(nums.begin(), nums.end() -k);
        reverse(nums.begin(), nums.end());
    }
};