/******************************************************************************
https://leetcode.com/problems/backspace-string-compare/

7.11.2021
*******************************************************************************/

class Solution {
public:
    bool backspaceCompare(string s, string t) {

        string s1;
        string t1;
        for (char ch : s){
            if (ch != '#'){
                s1.push_back(ch);
            }else if (!s1.empty()){
                s1.pop_back();
            }    
        }
        
        for (char ch : t){
            if (ch != '#'){
                t1.push_back(ch);
            }else if (!t1.empty()){
                t1.pop_back();
            }
        }
        return t1 == s1;
    }
};