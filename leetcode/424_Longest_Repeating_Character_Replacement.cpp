/******************************************************************************
https://leetcode.com/problems/longest-repeating-character-replacement/

1.24.2022
*******************************************************************************/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res{0};
        vector<int> counts(26, 0);
        int maxCharCount = 0;
        int left = 0, right = 0;
        for (; right < s.length(); right++){
            counts[s[right] - 'A']++;
            
            maxCharCount = max(maxCharCount, counts[s[right] - 'A']);
            if (right - left + 1 - maxCharCount > k){
                counts[s[left] - 'A']--;
                left++;
                
                maxCharCount = *(max_element(counts.begin(), counts.end()));
            }
            res = max(res, right - left + 1);
        }
            return res;
    }
};