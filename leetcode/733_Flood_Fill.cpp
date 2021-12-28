/******************************************************************************
https://leetcode.com/problems/flood-fill/

12.27.21
*******************************************************************************/

class Solution {
private:
    void dfsFill(vector<vector<int>>& image, int sr, int sc, int newColor, vector<vector<bool>>& visited, int oldColor){
        if (sr >= image.size() || sr < 0 || sc >= image[0].size() || sc < 0 || visited[sr][sc] == true || image[sr][sc] != oldColor){
            return;
        }
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; i++){
            dfsFill(image, sr + dirs[i][0], sc + dirs[i][1], newColor, visited, oldColor);
        }
    }
    
public:
    //dfs
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor){
            return image;
        }
        
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
        
        dfsFill(image, sr, sc, newColor, visited, oldColor);
        return image;
    }
};

/*
//bfs
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        pair<int, int> point = {sr, sc};
        int oldColor = image[sr][sc];
        if (oldColor == newColor){
            return image;
        }
        
        queue<pair<int, int>> q;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        q.push(point);
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            
            int row = p.first;
            int col = p.second;

            if (row < 0 || row >= image.size() ||col < 0 || col >= image[0].size() || image[row][col] != oldColor){
                continue;
            }
            
            image[row][col] = newColor;
            
            for (int i = 0; i < 4; i++){
                pair<int, int> neighbor = {row + dirs[i][0], col + dirs[i][1]};
                q.push(neighbor);
            }
        }
        return image;
    }
*/