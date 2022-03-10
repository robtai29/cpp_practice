/******************************************************************************
https://leetcode.com/problems/largest-perimeter-triangle/

2.27.2022
*******************************************************************************/


class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        int i = 0;
        
        for (; i+2 < nums.size(); i++){
            if (nums[i] < nums[i+1] + nums[i+2]){
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }   
            return 0;
    }
};