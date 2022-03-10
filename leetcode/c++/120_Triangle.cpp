/******************************************************************************
https://leetcode.com/problems/triangle/

1.1.2022
*******************************************************************************/

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) 
    {
        vector<vector<int>> memo(triangle);
        
        for (int row = memo.size() -2; row >= 0; row--){
            for(int col = 0; col < memo[row].size(); col++){
                memo[row][col] = memo[row][col] + min(memo[row+1][col], memo[row+1][col+1]);
            }
        }
        return memo[0][0];
    }
};

/*
    int minimumTotal(vector<vector<int> > &triangle) 
    {
        //bottom up
        vector<int> memo = triangle.back();
        for ( int i = triangle.size() - 2; i>= 0 ; --i ) //start from 2nd to bottom row and work towards the top
            for ( int j = 0; j < triangle[i].size() ; ++ j )
                memo[j] = triangle[i][j] + min(memo[j], memo[j+1]);
        return memo[0];
    }
    */