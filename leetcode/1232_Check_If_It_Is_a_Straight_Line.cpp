/******************************************************************************
https://leetcode.com/problems/check-if-it-is-a-straight-line/

11.8.21
*******************************************************************************/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coor) {
     
        for(int i=2;i<coor.size();i++)
        {
            if ((coor[1][1] - coor[0][1]) * (coor[i][0] - coor[0][0]) != (coor[i][1] - coor[0][1]) * (coor[1][0] - coor[0][0])){
                return false;
            }
        }
        return true;
    }
};
