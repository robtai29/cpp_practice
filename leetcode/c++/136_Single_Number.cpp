/******************************************************************************
https://leetcode.com/problems/single-number/

1.2.2022
*******************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res{0};
        for (int num : nums){
            res = res^num;
        }
        return res;
    }
};