/******************************************************************************
https://leetcode.com/problems/longest-common-prefix/

11.28.2021
*******************************************************************************/

class Solution {
private:
    int longestCommonPrefix(const string& s1, const string& s2, int size){
        int len = 0;
        for (int i = 0, j = 0; i < size && j < size; i++, j++){
            if (s1[i] == s2[j]){
                len++;
            }else{
                break;
            }
        }
        return len;
    }
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0){
            return "";
        }
        
        if (strs.size() == 1){
            return strs[0];
        }
        
        int maxLen = strs[0].length();
        for (int i = 1; i < strs.size(); i++){
            maxLen = min (maxLen, longestCommonPrefix(strs[i-1], strs[i], maxLen));
        }
        return strs[0].substr(0, maxLen);
    }
};