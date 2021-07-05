/******************************************************************************
https://leetcode.com/problems/valid-anagram/

7.4.2021
*******************************************************************************/

class Solution {
public:
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
};