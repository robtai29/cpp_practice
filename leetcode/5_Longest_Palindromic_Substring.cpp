/******************************************************************************
https://leetcode.com/problems/longest-palindromic-substring/

1.13.2022
*******************************************************************************/

class Solution {
private:
    string isPalindrome(string str, int left, int right){
        while (0 <= left && right < str.length()){
            if (str[left] == str[right]){
                left--;
                right++;
            }else{
                break;
            }
        }
        
        int len = right -left - 1;
        string res;
        if (len <= 0){
            return res;
        }
        return str.substr(left +1, len);   
    }
    
public:
    string longestPalindrome(string s) {
    string res;    
    
        for (int i = 0; i < s.length(); i++){
            string oddStr = isPalindrome(s, i, i);
            string evenStr = isPalindrome(s, i, i + 1);
            
            if (max(oddStr.length(), evenStr.length()) > res.length()){
                res = oddStr.length() > evenStr.length() ? oddStr : evenStr;
            }
        }
        return res;
    }
};