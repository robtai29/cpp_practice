/******************************************************************************
https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

10.8.21
*******************************************************************************/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<int> v(nums);
        sort(begin(v), end(v));
        int size = v.size();
        
        int res{0};
        
        for (int i = 0; i < size/2; i++){
            int sum = v[i] + v[size-1-i];
            res = max(res, sum);
        }
        return res;
    }
};