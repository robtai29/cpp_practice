/******************************************************************************
https://leetcode.com/problems/palindromic-substrings/

1.14.22
*******************************************************************************/

class Solution {
private:
    int countPalindrome(int left, int right, const string& s){
        int res{0};
        while (left >= 0 && right < s.length() && s[left] == s[right]){
            res++;
            left--;
            right++;
        }
        return res;
    }
    
public:
    int countSubstrings(string s) {
        int res = 0;
        
        for (int i = 0; i < s.length(); i++){
            res += countPalindrome(i, i, s);
            res += countPalindrome(i, i +1 , s);
        }
        return res;
    }
};