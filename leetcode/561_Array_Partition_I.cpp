/******************************************************************************
https://leetcode.com/problems/array-partition-i/

11.28.21
*******************************************************************************/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res{0};
        
        for (int i = 1; i < nums.size(); i=i+2){
         res += min(nums[i], nums[i -1]);   
        }
        
        return res;
    }
};