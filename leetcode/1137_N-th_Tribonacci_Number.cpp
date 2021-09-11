/******************************************************************************
https://leetcode.com/problems/n-th-tribonacci-number/

9.9.21
*******************************************************************************/

class Solution {
public:
    //bottom up iterative
    int tribonacci(int n) {
        vector<int> v(n+4, 0);
        v[0] = 0;
        v[1] = 1;
        v[2] = 1;
        
        for (int i = 3; i <= n; i++){
            v[i] = v[i-3] + v[i-2] + v[i-1];
        }
        
        return v[n];
        
    }
};

/*
class Solution {
public:
    //top down + memoization
    int tribonacci(int n, vector<int>& v){
        if (n < 0){
            return 0;
        }
        
        if (v[n] == INT_MIN){
            v[n] = tribonacci(n-1, v) +tribonacci(n-2, v)+ tribonacci(n-3, v);
            return v[n];
        }
        return v[n];
    }
    
    
    int tribonacci(int n) {
        vector<int> memo(n+3, INT_MIN);
        memo[0] =0;
        memo[1] =1;
        memo[1] =1;
        
        return tribonacci(n, memo);
    }
};
*/