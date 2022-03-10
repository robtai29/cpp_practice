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

/*
class UnionFind{
private:
    int size;
    vector<int> root;
    vector<int> rank;
    
public:
    UnionFind(int size_): size(size_), root(size_), rank(size_){
        for (int i = 0; i < size; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    int find(int x){
        if (root[x] == x){
            return x;
        }
        
        root[x] = find(root[x]);
        return root[x];
    }
    
        void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY){
            return;
        }
        
        if (rank[rootX] > rank[rootY]){
            root[rootY] = root[rootX]; 
        }else if (rank[rootY] > rank[rootX]){
            root[rootX] = root[rootY];
        }else{
             root[rootY] = root[rootX];
             rank[rootX]++;
        }
            size--;
    }
    
    int getSize(){
        return size;
    }
};
    
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        UnionFind uf(m * n);
        int numZeroes = 0;
        int dir[2][2] = {{1, 0}, {0, 1}};
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '0'){
                    numZeroes++;
                }
                
                if (grid[i][j] == '1'){
                    
                    for (int k = 0; k < 2; k++){
                        int newR = i + dir[k][0];
                        int newC = j + dir[k][1];
                        
                        if (newR >= 0 && newR < m && newC >= 0 && newC < n && grid[newR][newC] == '1'){
                            uf.unionSet(i * n + j, newR * n + newC);
                        }
                    }
                }
            }
        }
        return uf.getSize() - numZeroes;
    }
};
*/