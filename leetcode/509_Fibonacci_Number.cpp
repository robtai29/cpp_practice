/******************************************************************************
https://leetcode.com/problems/fibonacci-number/

9.6.21
*******************************************************************************/

//bottom up iterative
class Solution {
public:
    int fib(int n) {
        
        vector<int> v(n+2, 0);
        v[0] = 0;
        v[1] = 1;
        
        for (int i = 2; i <= n; i++){
            v[i] = v[i-1] + v[i-2];
        }

        return v[n];
        
    }
};
/*
top down

class Solution {
public:
    
    int fib(int n, vector<int>& v){
        
        if (v[n] != INT_MIN){
            return v[n];
        }else{
            v[n] = fib(n-1, v) + fib(n-2, v);
                    return v[n];
        }

        
    }
    
    
    int fib(int n) {
        if (n <= 1){
            return n;
        }
        
        vector<int> v(n+1, INT_MIN);
        v[0] = 0;
        v[1] = 1;
        
        return fib(n, v);
    }
};

*/