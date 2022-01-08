/******************************************************************************
https://leetcode.com/problems/non-overlapping-intervals/

1.7.2021
*******************************************************************************/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& interval1, const auto& interval2){
           return interval1[1] < interval2[1]; 
        });
        
        int res = 0;
        int end = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] < end){
                res++;
            }else{
                end = intervals[i][1];
            }
        } 
        return res;
    }
};