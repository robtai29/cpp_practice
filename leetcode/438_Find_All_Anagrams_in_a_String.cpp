/******************************************************************************
https://leetcode.com/problems/find-all-anagrams-in-a-string/

1.24.2022
*******************************************************************************/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        if (s.length() < p.length()){
            return {};
        }
        vector<int> res;
        
        vector<int> letters(26, 0);
        for (char ch : p){
            letters[ch - 'a']--;
        }
        
        int count = 0;
        for (int left = 0, right = 0; right < s.length(); right++){
            if (letters[s[right] - 'a'] < 0){
                count++;
            }
            letters[s[right] - 'a']++;
            
            if (right >= p.length()){
                if (letters[s[left] - 'a'] <= 0){
                    count--;
                }
                letters[s[left] - 'a']--;
                left++;
            }
            
            if (count == p.length()){
                res.push_back(left);
            }
        }
        return res;
    }
};