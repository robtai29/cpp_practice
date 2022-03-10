/******************************************************************************
https://leetcode.com/problems/relative-sort-array/

11.8.21
*******************************************************************************/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m;
        
        for (int num : arr1){
            m[num]++;
        }
        
        vector<int> res;
        
        for (int num : arr2){
            while (m[num] > 0){
                res.push_back(num);
                m[num]--;
            }
        }

        for (auto& entry : m){
            while (entry.second > 0){
                res.push_back(entry.first);
                entry.second--;
            }
        }
        return res;
    }
};