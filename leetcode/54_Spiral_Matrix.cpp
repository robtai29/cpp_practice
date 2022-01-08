/******************************************************************************
https://leetcode.com/problems/spiral-matrix/

1.8.2022
*******************************************************************************/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;
        int r = 0;
        int c = 0;
        
        while (res.size() < m * n){
            res.push_back(matrix[r][c]);
            seen[r][c] = true;
            
            int nextR = r + dirs[direction][0];
            int nextC = c + dirs[direction][1];
            
            if (0 <= nextR && nextR < m && 0 <= nextC && nextC < n && 
                !seen[nextR][nextC]){
                r = nextR;
                c = nextC;
            }else{
                direction = (direction + 1) % 4;
                r += dirs[direction][0];
                c += dirs[direction][1];   
            }
        }
        return res;
    }
};