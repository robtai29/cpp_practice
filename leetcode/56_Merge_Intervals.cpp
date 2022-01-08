/******************************************************************************
https://leetcode.com/problems/merge-intervals/

1.6.2022
*******************************************************************************/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& interval1, auto& interval2){
           return interval1[0] < interval2[0]; 
        });
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int left = 0, right = 1; right < intervals.size(); right++){
            if (res[left][1] >= intervals[right][0]){
                res[left][1] = max(res[left][1], intervals[right][1]);
            }else{
                res.push_back(intervals[right]);
                left++;
            }
        }
        return res;
    }
};