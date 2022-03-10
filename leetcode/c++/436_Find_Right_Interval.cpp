/******************************************************************************
https://leetcode.com/problems/find-right-interval/

1.30.22
*******************************************************************************/

class Solution {
private:
    int modifiedLowerBound(vector<pair<int, int>>& starts, int value){
        int left = 0;
        int right = starts.size() -1;
        
        while (left < right){
            int mid = left + (right - left) / 2;
            if (starts[mid].first == value){
                return starts[mid].second;
            }else if (starts[mid].first < value){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return starts[left].first < value ? -1 : starts[left].second;
    }
    
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> map;
        int n = intervals.size();
        vector<int> res(n, 0);
        
        for (int i = 0; i < n; i++){
            int start = intervals[i][0];
            map.push_back({start, i});
        }
        
        sort(map.begin(), map.end());
        
        for (int i = 0; i < n; i++){
            int target = intervals[i][1];
            
            int lower_bound_index = modifiedLowerBound(map, target);
            
            res[i] = lower_bound_index;
            
        }
            return res;
    }
};

/*
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> map;
        int n = intervals.size();
        vector<int> res(n, 0);
        
        for (int i = 0; i < n; i++){
            int start = intervals[i][0];
            map.push_back({start, i});
        }
        
        sort(map.begin(), map.end());
        
        for (int i = 0; i < n; i++){
            int end = intervals[i][1];
            auto nextStartPtr = lower_bound(map.begin(), map.end(), end, [](auto& interval, int target){
                    return interval.first < target; 
            });
            
            res[i] = nextStartPtr == map.end() ? -1 : nextStartPtr -> second;
            
        }
            return res;
    }
};
*/
