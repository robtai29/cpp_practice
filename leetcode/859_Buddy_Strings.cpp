/******************************************************************************
https://leetcode.com/problems/buddy-strings/

10.2.2021
*******************************************************************************/

class Solution {

private:
        bool containsDuplicates(const string& str){
            unordered_map<char, int> m;
            
            for (char ch : str){
                m[ch]++;
                
                if (m[ch] == 2){
                    return true;
                }
            }
            return false;
        }
    
    
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()){
            return false;
        }
        
        if (s == goal && containsDuplicates(s)){
            return true;
        }
        
        vector<int> arr;
        
        for (int i = 0; i < s.length(); i++){
            if (s[i] != goal[i]){
                arr.push_back(i);
            }
        }
        
        if (arr.size() != 2){
            return false;
        }
        
        int first = arr[0];
        int second = arr[1];
        
        return s[first] == goal[second] && s[second] == goal[first];
    }
};