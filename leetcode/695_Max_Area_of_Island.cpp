/******************************************************************************
https://leetcode.com/problems/max-area-of-island/

11.8.21
*******************************************************************************/

class Solution {

private:
    int maxAreaHelper(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return 0;
        }
        
        if (visited[i][j] == true || grid[i][j] == 0){
            return 0;
        }
        
        visited[i][j] = true;
        return 1 + maxAreaHelper(grid, visited, i + 1, j) + maxAreaHelper(grid, visited, i - 1, j) +            maxAreaHelper(grid, visited, i, j + 1) + maxAreaHelper(grid, visited, i, j - 1);
    }
    
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int max_area = 0;
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1 && visited[i][j] == false){
                    max_area = max(max_area, maxAreaHelper(grid, visited, i, j));
                }
            }
        }
        return max_area;
    }
};