/******************************************************************************
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

11.29.21
*******************************************************************************/
class Solution {
public:
//two pointers approach
    string removeDuplicates(string s) {
        string res(s);
        
        int i = 0, n = res.length();
        
        for (int j = 0; j < n; i++, j++){
           res[i] = res[j];
        
            if (i > 0 && res[i] == res[i-1]){
                i = i -2;
            }
        }
        
        return res.substr(0, i);
    }
};
/*
//using string as a stack
    string removeDuplicates(string s) {
        string res;
        
        for (const char& ch : s){
            if (res.length() == 0){
                res.push_back(ch);
            }else if (res.back() == ch){
                res.pop_back();
            }else{
                res.push_back(ch);
            }
        }
        return res;  
    }
*/

/*
//using a real stack
 string removeDuplicates(string str) {
    if (str.length() == 0){
        return str;
    }
        stack<char> s;
        s.push(str[0]);
        
        for (int i = 1; i < str.size(); i++){
            char first = s.empty() ? 0 : s.top();
            char second = str[i];
            if (first == second){
                s.pop();
            }else{
                s.push(second);   
            }
        }
        
        string res;
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
*/