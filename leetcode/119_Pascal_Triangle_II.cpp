/******************************************************************************
https://leetcode.com/problems/pascals-triangle-ii/

11.29.2021
*******************************************************************************/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0){
            return {1};
        }
        
        if (rowIndex == 1){
            return {1, 1};
        }
        
         vector<int> parent = getRow(rowIndex -1);
         vector<int> res(parent.size() + 1, 1);
        
         for (int i = 1; i+ 1 < res.size(); i++){
            res[i] = parent[i-1] + parent[i];
         }
        
        return res;
    }
};


/*
    vector<int> getRow(int rowIndex) {
        vector<int> parent(1, 1);
        if (rowIndex == 0){
            return parent;
        }
        
        for (int i = 0; i < rowIndex; i++){
            vector<int> res(1 + parent.size(), 1);
            
            for (int j = 1; j + 1 < res.size() ; j++){
                res[j] = parent[j-1] + parent[j];            
            }
            parent = res;
        }
        
        return parent;
    }
*/