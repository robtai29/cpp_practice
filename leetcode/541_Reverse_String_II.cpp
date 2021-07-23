/******************************************************************************
https://leetcode.com/problems/reverse-string-ii/

7.11.2021
*******************************************************************************/

class Solution {
public:
    string reverseStr(string s, int k) {

        int start = 0;
        int end = 0;
        
        while (start < s.length()){
            
            end = start + k;
          if (start + k >= s.length()){
              end = s.length();
          }
            
            
          reverse(s.begin() + start, s.begin() + end);
            start = start + 2* k;
            
        }
     return s;   
    }
    
};