/******************************************************************************
https://leetcode.com/problems/is-subsequence/

9.9.2021
*******************************************************************************/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() > 0 && t.length() == 0){
            return false;
        }else if (s.length()== 0){
            return true;
        }
        
        if (s[0]==t[0]){
            return isSubsequence(s.substr(1), t.substr(1));
        }else{
            return isSubsequence(s, t.substr(1));
        }
    }
};

/*
  bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> m;
        
        for (int i = 0; i < t.length(); i++){
            m[t[i]].push_back(i);
        }

        int prev = -1;
        
        for (char ch : s){
            vector<int>& v = m[ch];
            if (v.empty()){
                return false;
            }
            
            int pos = upper_bound(v.begin(), v.end(), prev) - v.begin();
            if (pos == v.size()){
                return false;
            }
            
            prev = v[pos];
        }
            return true;

    }
    */

