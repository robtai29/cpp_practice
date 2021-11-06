/******************************************************************************
https://leetcode.com/problems/permutation-in-string/

11.4.21
*******************************************************************************/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int letters[26] = {0};
        int l1 = s1.length();
        int l2 = s2.length();
        int count = s1.length();
        
        for (const char ch : s1){
            letters[ch - 'a']--;
        }
        
        for (int r = 0, l = 0; r < l2; r++){
            if (letters[s2[r] - 'a'] < 0){
                count--;
            }
            letters[s2[r] - 'a']++;
            
            if (r >= l1){
                if (letters[s2[l] - 'a'] <=0){
                    count++;
                }
                
                letters[s2[l] -'a']--;
                l++;
            }
            if (count == 0){
                break;
            }
        }
        return count == 0;
    }
};