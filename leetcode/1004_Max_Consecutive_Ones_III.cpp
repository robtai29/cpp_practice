/******************************************************************************
https://leetcode.com/problems/max-consecutive-ones-iii/

1.24.22
*******************************************************************************/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int ones = 0;
        int zeroes = 0;
        
        for (int left = 0, right = 0; right < nums.size(); right++){
            if (nums[right] == 1){
                ones++;
            }else{
                zeroes++;
            }
            
            while (left <= right && zeroes > k){
                if (nums[left] == 1){
                    ones--;
                }
                if (nums[left] == 0){
                    zeroes--;
                }
                
                left++;
            }

            res = max(res, ones + min(zeroes, k));
        }
        return res;
    }
};