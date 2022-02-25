/******************************************************************************
https://leetcode.com/problems/valid-palindrome-ii/

2.24.22
*******************************************************************************/

class Solution {
public:
    bool validPalindromeCheck(string& s, int l, int r){
        while (r > l){
            if (s[r]!= s[l]){
                return false;
            }
            r--;
            l++;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.length()-1;
        
        while (right > left){
            if (s[right] != s[left]){
                return validPalindromeCheck(s, left + 1, right) || validPalindromeCheck(s, left, right -1);
            }
            right--;
            left++;
        }
        return true;
    }
};