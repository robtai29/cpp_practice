/******************************************************************************
https://leetcode.com/problems/insert-interval/

1.6.2022
*******************************************************************************/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];
        for (; i < intervals.size() && intervals[i][1] < start; i++){
            res.push_back(intervals[i]);
        }
        
        while (i < intervals.size() && intervals[i][0] <= end){
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        
        res.push_back(vector<int>{start, end});
        
        while (i < intervals.size()){
            res.push_back(intervals[i]);
            i++;
            
        }
        
        return res;
        
    }
};