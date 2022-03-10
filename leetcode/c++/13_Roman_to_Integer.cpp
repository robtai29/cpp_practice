/******************************************************************************
https://leetcode.com/problems/roman-to-integer/

10.26.2021
*******************************************************************************/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m = {
            
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int res{0};
        for (int i = s.length() -1; i >= 0; i--){
            
            int val = m[s[i]];
            if (i < s.length() && m[s[i+1]] > m[s[i]]){
                val *= -1;
            }
            res += val;
        }                           
            return res;
    }
};