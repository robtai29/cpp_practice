/******************************************************************************
https://leetcode.com/problems/degree-of-an-array/

10.2.21
*******************************************************************************/

class Solution {
public:
    int findShortestSubArray(vector<int>& A) {
        unordered_map<int, int> count, first;
        int res = INT_MAX, degree = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (count[A[i]] == 0){
                first[A[i]] = i;
            }
            
            count[A[i]]++;
            
            if (count[A[i]] > degree){
                degree = count[A[i]];
                res = i - first[A[i]] + 1;
            }
            
            if (count[A[i]] == degree){
                res = min(res, i - first[A[i]] + 1);
            }
        }
        return res;
    }
};