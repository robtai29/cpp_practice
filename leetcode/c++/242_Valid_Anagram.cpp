/******************************************************************************
https://leetcode.com/problems/valid-anagram/

7.4.2021
*******************************************************************************/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()){
            return false;
        }
        
        int letters[26] = {};
        for (int i = 0; i < s.length(); i++){
            letters[s[i] - 'a']++;
            letters[t[i] - 'a']--;
        }
        
        for (int j = 0; j < 26; j++){
            if (letters[j] != 0){
                return false;
            }
        }
        return true;
    }
};

/*
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        
        for (char ch : s){
            map[ch]++;
        }
        
        for (char ch : t){
            map[ch]--;
        }
        
        for (auto entry : map){
            if (entry.second != 0){
                return false;
            }
        }
        
        return true;
    }
*/