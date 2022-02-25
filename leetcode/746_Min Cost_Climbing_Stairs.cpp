/******************************************************************************
https://leetcode.com/problems/min-cost-climbing-stairs/

9.6.21, 2.13.22
*******************************************************************************/

class Solution{
private:

    int helper(int i, vector<int>& cost, vector<int>& memo){
            if (i < 2){
                return 0;
            }
            
            if (memo[i] == -1){
                   memo[i]  = min(cost[i-1] + helper(i-1, cost, memo), cost[i-2] + helper(i-2, cost, memo));
            }
                                  
            return memo[i];
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n + 1, -1);
        return helper(n, cost, memo);
    }
};

/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n < 2){
            return 0;
        }
       vector<int> dp(n+ 1, 0);
        for (int i = 2; i < dp.size(); i++){
            
            dp[i] = min(cost[i-1] + dp[i-1], cost[i-2] + dp[i-2]);
        }
        
        return dp[dp.size() -1];
    }
};



*/