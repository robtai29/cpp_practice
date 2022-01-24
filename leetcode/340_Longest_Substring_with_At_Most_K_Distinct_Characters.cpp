/******************************************************************************
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

1.23.22
*******************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        unordered_map<char, int> m;
        int count = 0;
        int res = 0;
        for (int right = 0, left = 0; right < s.length(); right++){
            if (m[s[right]] == 0){
                count++;
                
            }
                m[s[right]]++;
                
            while (count > k){
                if (m[s[left]]==1){
                    count--;
                }
                m[s[left]]--;
                left++;
            }
            res = max (res, right - left + 1);

        }
         return res;
    }
};