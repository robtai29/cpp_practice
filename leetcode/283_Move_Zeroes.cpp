/******************************************************************************
https://leetcode.com/problems/move-zeroes/

7.5.2021
*******************************************************************************/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
