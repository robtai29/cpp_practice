/******************************************************************************
https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

11.21.2021
*******************************************************************************/

class Solution {
private:
    //return upperbound of -1 ie the first smallest positive number 
    int countNegativesHelper(const vector<vector<int>>& grid, int row){
        int low = 0;
        int high = grid[0].size() -1;
        
        while (high >= low){
            int mid = low + (high - low) / 2;
            if (grid[row][mid] > -1){
                low = mid + 1;
            }else{
                high = mid -1;
            }   
        }
         // high is the index for the last non-negative number
        // high + 1 is the number of non-negative numbers
        // size - (high + 1) is the number of negative numbers
        return high;
    }
    
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rowCount = grid.size();
        int colCount = grid[0].size();
        int res{0};
        
        
        for (int row = 0; row < rowCount; row++){
           int upperBound = countNegativesHelper(grid, row);  
           res += (colCount - upperBound - 1); 
        }
        return res;
    }
};

/*
    int countNegatives(vector<vector<int>>& grid) {
        //going through the stairchase of negative from the bottom up
        int rowCount = grid.size();
        int colCount = grid[0].size();
        int res{0};
        int col = 0;
        
        for (int row = rowCount -1; row >= 0; row--){
           for (; col < colCount; col++){
               if (grid[row][col] < 0){
                   res += colCount - col;
                   break;
               }
           }    
        }
        return res;
    }
*/