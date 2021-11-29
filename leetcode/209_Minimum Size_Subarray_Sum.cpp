/******************************************************************************
https://leetcode.com/problems/minimum-size-subarray-sum/

11.28.2021
*******************************************************************************/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }
         int sum = 0, distance = INT_MAX;
        
        for (int right = 0, left = 0; right < nums.size(); right++){
            sum+= nums[right];
        
            while(sum >= target){
                distance = min(distance, right - left + 1);
                sum -= nums[left];
                left++;            
            }
        }
            return distance == INT_MAX ? 0 : distance;
    }
};

/*
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = nums[0];
        
        while (right < nums.size()){
            
            if (sum >= target){
                res = min(res, right - left + 1);
                if (left < nums.size() && left <= right){
                    sum -= nums[left];
                    left++;
                }
            }else{
                right++;
                if (right < nums.size()){
                sum += nums[right];
                }
            }                    
        }
            return res == INT_MAX ? 0 : res;
    }
*/