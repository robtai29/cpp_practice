/******************************************************************************
https://leetcode.com/problems/flood-fill/

11.6.21
*******************************************************************************/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        pair<int, int> point = {sr, sc};
        int oldColor = image[sr][sc];
        
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false)); //just to practice 
        queue<pair<int, int>> q;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        q.push(point);
        
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            
            int row = p.first;
            int col = p.second;
            if (row < 0 || row >= image.size()){
                continue;
            }
            
            if (col < 0 || col >= image[0].size()){
                continue;
            }
            
            if (image[row][col] != oldColor || visited[row][col] == true){
                continue;
            }
            visited[row][col] = true;
            image[row][col] = newColor;
            
            for (int i = 0; i < 4; i++){
                pair<int, int> neighbor = {row + dirs[i][0], col + dirs[i][1]};
                q.push(neighbor);
            }
        }
        return image;
    }
};