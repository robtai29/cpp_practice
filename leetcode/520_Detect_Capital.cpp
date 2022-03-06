/******************************************************************************
https://leetcode.com/problems/detect-capital/

2.25.22
*******************************************************************************/

class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCount{0};
        
        for (char ch : word){
            
            if (ch >= 'a' && ch <= 'z'){
                capCount++;
            }
        }
        
        if (capCount == 0 || capCount == word.size() || (capCount == word.size() -1 && isupper(word[0]))){
            return true;
        }
        return false;
    }
};