/******************************************************************************
https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

2.27.2022
*******************************************************************************/


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<array<char, 2>> mis;
        
        for (int i = 0; i < s1.length() && mis.size() < 3; i++){
            if (s1[i] != s2[i]){
                
                mis.push_back({mis.empty() ? s1[i] : s2[i], mis.empty() ? s2[i] : s1[i]});   
            }
        }
        
        return mis.empty() || (mis.size() == 2 && mis[0] == mis[1]);
    }
};
/*
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        
        for (int i = 0; i < s1.length(); i++){
            if (s1[i] != s2[i]){
                diff++;
            }
            
        }
        
        vector<int> letters(26, 0);
        for (char ch : s1){
            letters[ch - 'a']++;
        }
        
        for (char ch : s2){
            letters[ch-'a']--;
        }
        
        int sum = 0;
        for (int num : letters){
            sum += abs(num);
        }
        
        return sum == 0 && diff < 3;
    }
};
*/