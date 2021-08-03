/******************************************************************************
https://leetcode.com/problems/longest-palindrome/

8.3.2021
*******************************************************************************/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> set;
        int res{0};
        
        for (char ch : s){
            
            auto findItr = set.find(ch);
            if (findItr == end(set)){
                set.insert(ch);
            }else{
                res = res + 2;
                set.erase(findItr);
            }
            
        }
        
        return set.empty() ? res : res + 1;
        
    }
};