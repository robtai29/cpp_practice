/******************************************************************************
https://leetcode.com/problems/build-an-array-with-stack-operations/

11.21.2021
*******************************************************************************/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        for (int i = 0, counter = 1; i < target.size() && counter <= n; counter++){
            if (target[i] == counter){
                res.push_back("Push");
                i++;
            }else{
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};