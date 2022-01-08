/******************************************************************************
https://leetcode.com/problems/word-search/

1.8.2022
*******************************************************************************/

class Solution {
private:
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& seen, int i, int j, const string& word, int step){
        if (step == word.length()){
            return true;
        }
        
    int m = board.size(), n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || seen[i][j]){
            return false;
        }
        
        if (word[step] != board[i][j]){
            return false;
        }
        
        seen[i][j] = true;
        step++;
        
        bool res = exist(board, seen, i + 1, j, word, step) ||
            exist(board, seen, i - 1, j, word, step) ||
            exist(board, seen, i, j + 1, word, step) ||
            exist(board, seen, i, j -1, word, step);
        seen[i][j] = false;
        
        return res;
    }
        
    public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == word[0]){
                    vector<vector<bool>> seen(m, vector<bool>(n, false));
                
                    if (exist(board, seen, i, j, word, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};