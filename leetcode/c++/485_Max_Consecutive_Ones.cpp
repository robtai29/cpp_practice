/******************************************************************************
https://leetcode.com/problems/max-consecutive-ones/

7.23.2021
*******************************************************************************/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res{0};
        int tempCount{0};
        
        for (int num : nums){
            if (num == 1){
                tempCount++;
                res = max(res, tempCount);
            }else{
                tempCount = 0;
            }
        }
        return res;
    }
};