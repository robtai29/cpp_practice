/******************************************************************************
https://leetcode.com/problems/max-area-of-island/

12.28.21
*******************************************************************************/

class Solution {
private:
    int bfsArea(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited){
        int m = grid.size(), n = grid[0].size();
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({row, col});
        int area = 0;
        while(!q.empty()){
            pair<int, int> point = q.front();
            q.pop();
            area++;
            visited[point.first][point.second] = true;
            for (int i = 0; i < 4; i++){
                int r = point.first + dirs[i][0];
                int c = point.second + dirs[i][1];
                
                if (r >= 0 && r < m && c >= 0 && c < n && visited[r][c] == false && grid[r][c] == 1){
                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }
        return area;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int area{0};
        
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (grid[row][col] == 1 && visited[row][col] == false){
                    area = max(area, bfsArea(grid, row, col, visited));
                }
            }
        }
        return area;
    }
};

/*
class Solution {
private:
    int maxAreaHelper(vector<vector<int>>& grid, int row, int col, vector<vector<bool>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        
        if (row >= m || row < 0 || col >= n || col < 0 || visited[row][col] == true || grid[row][col] == 0){
            return 0;
        }
        
        visited[row][col] = true;
        
        return 1 + maxAreaHelper(grid, row + 1, col, visited) + maxAreaHelper(grid, row -1, col, visited)
                + maxAreaHelper(grid, row, col + 1, visited) + maxAreaHelper(grid, row, col -1, visited);
    }
    
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int area = 0;
        
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                area = max(area, maxAreaHelper(grid, row, col, visited));
            }
        }
        return area;
    }
};
*/