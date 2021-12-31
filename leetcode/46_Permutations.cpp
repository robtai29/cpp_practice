/******************************************************************************
https://leetcode.com/problems/permutations/

12.30.2021
*******************************************************************************/

class Solution {
private:
    void permute(vector<vector<int>>& res, vector<int>& list, int position){
        if (position == list.size()){
            res.push_back(list);
        }else{
         for (int i = position; i < list.size(); i++){
            swap(list[position], list[i]);
             permute(res, list, position + 1);
             swap(list[position], list[i]);
         }
        }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> list(nums);
        permute(res, list, 0);
        return res;
    }
};