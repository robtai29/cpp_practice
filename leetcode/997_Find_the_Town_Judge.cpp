/******************************************************************************
https://leetcode.com/problems/find-the-town-judge/

11.11.2021
*******************************************************************************/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        //ppl = outdegree - indegree ; judge = n -1 indegree
        vector<int> ppl(n+1, 0);
        for (const auto& pair: trust){
            ppl[pair[0]]--;
            ppl[pair[1]]++;
        }
        
        for (int i = 1; i < n+1; i++){
            if (ppl[i] == n -1){
                return i;
            }
        }
        return -1;
    }
};