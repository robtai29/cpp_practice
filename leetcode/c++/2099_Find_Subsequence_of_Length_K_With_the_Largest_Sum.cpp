/******************************************************************************
https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

2.20.2022
*******************************************************************************/

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        
        for (int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
            if (pq.size() > k){
                pq.pop();
            }
            
        }
        
        vector<pair<int, int>> kPairs;
        while (!pq.empty()){
            int index = pq.top().second;
            int num = pq.top().first;
            pq.pop();
            kPairs.push_back({num, index});
        }
        
        sort(kPairs.begin(), kPairs.end(), [](pair<int, int>& p1, pair<int, int>& p2){
            return p1.second < p2.second;
        });
        
        vector<int> res;
        for (pair p : kPairs){
            res.push_back(p.first);
        }
        
        return res;
    }
};