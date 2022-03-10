/******************************************************************************
https://leetcode.com/problems/combinations/

12.30.2021
*******************************************************************************/

class Solution {
private:
    void combineHelper(vector<vector<int>>& res, vector<int>& combo, int n, int k, int num){
        if (combo.size() == k){
            res.push_back(combo);
        }else{
            
         for (int i = num; i <= n; i++){
             combo.push_back(i);
             combineHelper(res, combo, n, k, i + 1);
             combo.pop_back();
         }   
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> combo;
        combineHelper(res, combo, n, k, 1);
        return res;
    }
};