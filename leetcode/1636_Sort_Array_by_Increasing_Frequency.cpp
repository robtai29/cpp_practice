/******************************************************************************
https://leetcode.com/problems/sort-array-by-increasing-frequency/

2.20.2022
*******************************************************************************/

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums){
            m[num]++;
        }
        
        sort(nums.begin(), nums.end(), [&m](int a, int b){
            if (m[a] == m[b]){
                return a > b;
            }
            
            return m[a] < m[b];
        });
        
        return nums;
    }
};