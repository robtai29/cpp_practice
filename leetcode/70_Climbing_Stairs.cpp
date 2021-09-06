/******************************************************************************
https://leetcode.com/problems/plus-one/

7.20.2021
*******************************************************************************/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n + 3, 0);
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        
        for (int i = 3; i <= n; i++){
            v[i] = v[i-1] + v[i-2];
        }
        
        return v[n];
    }
};

/*
class Solution {
public:
    int climbStairs(int i, vector<int>& v){
        
        if (v[i] != INT_MIN){
            return v[i];
        }else{
            
            v[i] = climbStairs(i-1, v) + climbStairs(i-2, v);
            
            return v[i];
            
        }
        
        
    }
    
    
    int climbStairs(int n) {
     
        if (n <=2){
            return n;
        }
        vector<int> v(n+1, INT_MIN);
        v[1]=1;
        v[2] =2;
        
        return climbStairs(n, v);
        
    }
};
*/