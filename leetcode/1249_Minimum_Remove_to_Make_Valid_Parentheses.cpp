/******************************************************************************
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

2.24.22
*******************************************************************************/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int opens = 0;
        int closes = 0;
        
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                opens++;
            }
            
            if (s[i] == ')'){
                if (opens == 0){
                    s[i] = '*';
                }else{
                    opens--;
                }                
            }
        }
        
          for (int i = s.length() -1; i >= 0; i--){
            if (s[i] == ')'){
                closes++;
            }
            
            if (s[i] == '('){
                if (closes == 0){
                    s[i] = '*';
                }else{
                    closes--;
                }                
            }
        }
        
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};

/*
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                st.push(i);
            }
            
            if (s[i] == ')'){
                if (st.empty()){
                    s[i] = '*';
                }else{
                    st.pop();
                }   
            }
        }
        
        while (!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
        
    }
};
*/