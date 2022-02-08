/******************************************************************************


7.4.2021
*******************************************************************************/


class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& interval1, auto& interval2){
           return interval1[0] < interval2[0]; 
        });
        
        for (int i = 0; i+1 < intervals.size(); i++){
            if (intervals[i][1] >intervals[i+1][0]){
                return false;
            }
        }
        return true;
    }
};