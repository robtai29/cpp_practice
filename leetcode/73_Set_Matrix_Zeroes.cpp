/******************************************************************************
https://leetcode.com/problems/set-matrix-zeroes/

1.8.2022
*******************************************************************************/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //lesson learn: use index of array to mark some info
        
        //signify if there were zeroes on row/col to begin with
        bool colZero = false, rowZero = false;  
        int m = matrix.size(), n = matrix[0].size();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (matrix[i][j] == 0){
                    if (i == 0){
                        rowZero = true;
                    }
                    if (j == 0){
                        colZero = true;
                    }
            
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                if (matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (rowZero == true){
            for (int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
        
        if (colZero == true){
            for (int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        
    }
};