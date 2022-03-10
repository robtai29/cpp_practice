/******************************************************************************
https://leetcode.com/problems/longest-continuous-increasing-subsequence/

7.23.21
*******************************************************************************/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int times{1};
        int res{1};
        
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i-1]){
                times++;
                res = max(res, times);
            }else{
                times =1;
            }    
        }
        return res;
    }
};