/******************************************************************************
https://leetcode.com/problems/plus-one/

7.20.2021
*******************************************************************************/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int increment = 1;
        vector<int> res(digits);
        
        for (int i = res.size() -1; i >= 0; i--){
            

            res[i] = res[i] + increment;
            increment = res[i] == 10 ? 1 : 0;
            res[i] = res[i] % 10;
            
        }
        
        if (increment){
            res.insert(begin(res), 1);
        }
        
        return res;
        
    }
};