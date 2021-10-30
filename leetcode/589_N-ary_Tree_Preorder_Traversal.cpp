/******************************************************************************
https://leetcode.com/problems/n-ary-tree-preorder-traversal/

10.29.21
*******************************************************************************/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(r, vector<int>(c, 0));
        if ((m == r && n == c) || (r * c != m * n)){
            return mat;
        }
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
             int row = (i * n + j) / c;
             int col = (i * n + j) % c;
            res[row][col] = mat[i][j];
            }
        }
        return res;
    }
};