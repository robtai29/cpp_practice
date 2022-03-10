/******************************************************************************
https://leetcode.com/problems/rotate-image/

1.14.2022
*******************************************************************************/


class Solution {
public:
    /*
    123     789     741
    456     456     852
    789     123     963
    */
    
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 0; i < m /2; i++){
            for (int j = 0; j < n; j++){
                swap(matrix[i][j], matrix[m-i-1][j]);
            }
        }
        
       for (int i = 0; i < m; ++i) {
        for (int j = i; j < n; ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
        
        

        
    }
};