/******************************************************************************
https://leetcode.com/problems/truncate-sentence/

6.19.2021
*******************************************************************************/

class Solution {
public:
    string truncateSentence(string s, int k) {
        int length = s.length();
        int wordCount = 0;
        
        for (int i = 0; i < length; i++){
        
         if (s[i] == ' '){
             wordCount++;
         }
          
            if (wordCount == k){
                   
                s.erase(begin(s) + i, end(s));
                break;
            }            
        }

        return s;
    }
};