/******************************************************************************
https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

2.20.2022
*******************************************************************************/

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        //edge case
        if (points.size() == 0){
            return -1;
        }
  
        int resIndex = -1;
        int minDistance = INT_MAX;
        
        for (int i = 0; i < points.size(); i++){
            int a = points[i][0];
            int b = points[i][1];
            
            if (a == x || b == y){
                int distance = abs(x-a) + abs(y-b);
                if (distance < minDistance){
                    resIndex = i;
                    minDistance = min(minDistance, distance);
                }
            }
        }
        return resIndex;
    }
};