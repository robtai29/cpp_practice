/******************************************************************************
https://leetcode.com/problems/backspace-string-compare/

7.11.2021
*******************************************************************************/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length()-1;
        int skipS = 0;
        int j = t.length()-1;
        int skipT = 0;
        
        while (i >= 0 || j >= 0){
            //skip through chars that need to skipped so we can compare
            while(i >= 0 && (s[i] == '#' || skipS > 0)){
                if (s[i]== '#'){
                    skipS++;
                }else{
                    skipS--;
                }    
                i--;
            }
            
            while(j >= 0 && (t[j] == '#' || skipT > 0)){
                if (t[j] == '#'){
                    skipT++;
                }else{
                    skipT--;
                }
                j--;
            }
            
            if (i >= 0 && j >=0 && s[i] == t[j]){
                i--;
                j--;
                }else{
                    return i == -1 && j == -1;
                }
            }
        return true;
    }
};
/*
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
*/