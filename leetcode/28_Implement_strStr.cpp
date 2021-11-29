/******************************************************************************
https://leetcode.com/problems/implement-strstr/

11.28.2021
*******************************************************************************/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0){
            return 0;
        }
        
        vector<int> failureTable = lpsTable(needle);
        
        for (int i = 0, j = 0; i < haystack.length() && j < needle.size();){
            if (haystack[i] == needle[j]){
                i++;
                j++;
                if (j == needle.length()){
                return i-j;
                }
            }else{
                    j > 0 ? j = failureTable[j - 1] : i++;
                }
        }
        return -1;
    }
private:
    vector<int> lpsTable(string needle) {
        int n = needle.length();
        vector<int> table(n, 0);
        for (int i = 1, prev = 0; i < n;){
            if (needle[i] == needle[prev]){
                prev++;
                table[i] = prev;
                i++;
            }else if (prev > 0){  //more than one match already prior to mistmatch
                prev = table[prev-1];
            }else{                //mismatch prior any matching
                table[i] = 0;
                i++;
            }
        }
        
        return table;
    }
};