/******************************************************************************
https://leetcode.com/problems/height-checker/

11.20.21
*******************************************************************************/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int counter[101] = {};
        for (int i = 0; i < heights.size(); i++){
            counter[heights[i]]++;
        }
        
        int res{0};
        
        for (int i = 0, j = 0; i < heights.size() && j < 101; ){
            if (counter[j] == 0){
                j++;
                continue;
            }
            
            if (counter[j] > 0){
                counter[j]--;
                if (heights[i] != j){
                    res++;
                }   
                i++;
            }
        }
        return res;
    }
};