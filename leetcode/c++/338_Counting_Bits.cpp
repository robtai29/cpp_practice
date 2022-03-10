/******************************************************************************
https://leetcode.com/problems/counting-bits/

7.4.2021
*******************************************************************************/

class Solution {
public:
    vector<int> countBits(int n) {

        
        vector<int> v(n + 1, 0);

        
        for (int i = 1; i <= n; ++i){
            
            v[i] = v[i >> 1] + (i & 1);
            
        }
        
        return v;
    }
};