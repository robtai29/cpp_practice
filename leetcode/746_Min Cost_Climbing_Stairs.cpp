/******************************************************************************
https://leetcode.com/problems/min-cost-climbing-stairs/

9.6.21
*******************************************************************************/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       vector<int> v(cost.size() +1, 0);
        
        v[0] = 0;
        v[1] = 0;
        
        for (int i = 2; i < v.size(); i++){
            v[i] = min(v[i-1] + cost[i-1], v[i-2] + cost[i-2]);
            
        }
        
        return v[v.size()-1];
    }
};