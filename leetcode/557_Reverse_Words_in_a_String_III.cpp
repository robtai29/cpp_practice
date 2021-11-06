/******************************************************************************
https://leetcode.com/problems/reverse-words-in-a-string-iii/

6.20.21
*******************************************************************************/


class Solution {
public:
    string reverseWords(string s) {
        
        string result(s);
        
        int right = 0;
        int left = 0;
        
        for (int i = 0; i < result.length(); i++){
            if (result[i] == ' ' || i == result.length() -1){
                
                i < result.length()-1 ? right = i : right = result.length();
                
                reverse(begin(result) + left, begin(result) + right);
                
                left = i + 1;
                
                
            }
            
            
        }
        
        return result;
    }
};

/*
    string reverseWords(string s) {
        stringstream ss(s);
        string str;
        string res;
        while(ss >> str){
            reverse(str.begin(), str.end());
            res += str + " ";
        }
        
        res.erase(res.end() -1);
        return res;
    }
*/