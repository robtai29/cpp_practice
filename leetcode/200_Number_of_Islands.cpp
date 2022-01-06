/******************************************************************************
https://leetcode.com/problems/number-of-islands/

1/6/22
*******************************************************************************/

class Solution {
private:
    void dfsTraversal(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        
        if (row < 0 || row >= m || col < 0 || col >= n){
            return;
        }
        
        if (grid[row][col] != '1'){
            return;
        }
        
        grid[row][col] = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < 4; i++){
            dfsTraversal(grid, visited, row + dirs[i][0], col + dirs[i][1]);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (grid[row][col] == '1'){
                    count++;
                    dfsTraversal(grid, visited, row, col);
                }
            }
        }
        return count;
    }
};