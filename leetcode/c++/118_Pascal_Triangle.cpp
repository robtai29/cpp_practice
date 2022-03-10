/******************************************************************************
https://leetcode.com/problems/pascals-triangle/

11.25.2021
*******************************************************************************/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        
        for (int i = 1; i < numRows; i++){
            vector<int> v(i + 1, 0);
            v[0] = 1;
            v[v.size() -1] = 1;
            for (int j = 1; j + 1 < v.size(); j++){
                v[j] = res[i-1][j-1] + res[i-1][j];
                
            }
            res.push_back(v);
        }
        return res;
    }
};