/******************************************************************************
https://leetcode.com/problems/two-sum/

10.26.2021
*******************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (m.find(diff) != end(m)){
                res.push_back(i);
                res.push_back(m[diff]);
                return res;
            }
                m[nums[i]] = i;
            }

        return res;
    }
};