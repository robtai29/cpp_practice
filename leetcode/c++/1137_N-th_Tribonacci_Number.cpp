/******************************************************************************
https://leetcode.com/problems/n-th-tribonacci-number/

9.9.21
*******************************************************************************/

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+3);
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++){
            
            dp[i] = dp[i-1]+ dp[i-2] + dp[i-3];
        }
        
        return dp[n];
    }
};

/*
class Solution {
private:
    int tribonacci(int n, vector<int>& memo){
        if (n < 0){
            return 0;
        } 
        
        if (memo[n] == -1){
            memo[n] = tribonacci(n-1, memo) + tribonacci(n-2, memo) + tribonacci(n-3, memo);
        }
        return memo[n];
    }
    
public:
    int tribonacci(int n) {
        vector<int> memo(n + 3, -1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        
        return tribonacci(n, memo);
    }
};
*/