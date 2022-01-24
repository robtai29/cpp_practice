/******************************************************************************
https://leetcode.com/problems/longest-substring-without-repeating-characters/

1.23.2022
*******************************************************************************/

class Solution {
public:

    /*
    use a start and an end pointer to do this sliding window tecnqiue
    use a hashmap to record last time a particular char was encountered.
    if encountered before, end is updated.
    */
    
    int lengthOfLongestSubstring(string s) {
        int len{0};
        unordered_map<int, int> m;
        
        for (int left = 0, right = 0; right < s.length(); right++){
            if (m.count(s[right]) > 0){
                left = max(left, m[s[right]] + 1);
            }
                m[s[right]] = right;
                len = max(len, right - left + 1);
        
        }
        
            return len;
    }
};