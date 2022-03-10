/******************************************************************************
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

9.11.2021
*******************************************************************************/

class Solution {
public:
    
    void helper(vector<string>& res, vector<string>& letters, string str, string& digits, int pos){
        if (pos == digits.length()){
            res.push_back(str);
            return;
        }
        
        int num = digits[pos] - '0';
        string chars = letters[num];
        
        for (char ch : chars){
            string s = str + ch;
            helper(res, letters, s, digits, pos +1);   
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0){
            return vector<string>{};
        }
        vector<string> v{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        
        helper(res, v, "", digits, 0);
        return res;
    }
};