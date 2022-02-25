/******************************************************************************
https://leetcode.com/problems/sort-characters-by-frequency/

2.20.2022
*******************************************************************************/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        
        for (char ch : s){
            mp[ch]++;
        }
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<>> max_heap;
        for (auto entry : mp){
            
            max_heap.push({entry.second, entry.first});
            
        }

        string res;
        while(!max_heap.empty()){
            
            char ch = max_heap.top().second;
            int freq = max_heap.top().first;
            max_heap.pop();
                res += string(freq, ch);
            }
        return res;
    }
};