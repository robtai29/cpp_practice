/******************************************************************************
https://leetcode.com/problems/permutations/

1.13.2022
*******************************************************************************/

class Solution {
private:
    string countingSort(const string& str){
        //assume only lower case characters
        int letters[26] = {};
        for (char ch : str){
            letters[ch - 'a']++;
        }
        
        string res(str.length(), ' ');
        int count = 0;
        for (int i = 0; i < 26; i++){
            while(letters[i] > 0 && count < str.length()){
                res[count] = i + 'a';
                count++;
                letters[i]--;
            }
        }
        
        return res;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //use counting sort to generate a sorted string rather than using sort function
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for (string str : strs){
            string key = countingSort(str);
            m[key].push_back(str);
        }
        
        for (const auto& entry : m){
            res.push_back(entry.second);
        }
        
        return res;
    }
};

/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> m;
        for (string str : strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(str);
        }
        
        for (auto entry : m){
            res.push_back(entry.second);
        }
        
        return res;
    }
};
*/