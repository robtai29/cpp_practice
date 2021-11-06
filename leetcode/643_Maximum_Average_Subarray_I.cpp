/******************************************************************************
https://leetcode.com/problems/maximum-average-subarray-i/

11.6.21
*******************************************************************************/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        double sum = 0.0;
        double res = INT_MIN;
        
        for (int l = 0, r = 0; r < n; r++){
            sum += nums[r];
            if (r >= k){
                sum -= nums[l];
                l++;
            }
            if (r >= k-1){
                res = max(res, sum);
            }
        }
        return res / k;
    }
};
/*
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        
        double tempSum = 0.0;
        double ans = INT_MIN;
        
        for (int r = 0; r < k; r++){
            tempSum += nums[r];
        }
        
        ans = max(ans, tempSum / k);
        
        for (int l = 0, r = k; r < n; r++, l++){
            tempSum += nums[r];
            tempSum -= nums[l];
            ans = max(ans, tempSum / k);
        }
        
        return ans;
    }
};
*/