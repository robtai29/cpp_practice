/******************************************************************************
https://leetcode.com/problems/rotting-oranges/

12.31.2021
*******************************************************************************/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int answer = 0;
        int fresh = 0;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        
        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if (grid[row][col] == 1){
                    fresh++;
                }else if (grid[row][col] == 2){
                    q.push({row, col});
                }
            }
        }
        
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        if (fresh == 0){
            return 0;
        }
        while(fresh > 0 && !q.empty()){
            int size = q.size();
            
            while(size-- > 0){
                pair<int, int> point = q.front();
                q.pop();
                for (int i = 0; i < 4; i++){
                    int x = point.first + directions[i][0];
                    int y = point.second + directions[i][1];
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1){
                        continue;   
                    }
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                }
             answer++;
            }
            return fresh == 0 ? answer : -1;
        }
};