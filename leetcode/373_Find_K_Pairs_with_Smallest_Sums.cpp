/******************************************************************************
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

2.19.2022
*******************************************************************************/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        auto comp = [&nums1, &nums2](pair<int, int> p1, pair<int, int> p2){
             return nums1[p1.first] + nums2[p1.second] > nums1[p2.first] + nums2[p2.second];
        };
        
        //minheap
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        for (int i = 0; i < k && i < nums1.size(); i++){
            min_heap.push({i, 0});
        }
        
        while (k-- > 0 && !min_heap.empty()){
            int i = min_heap.top().first;
            int j = min_heap.top().second;
            min_heap.pop();
            res.push_back(vector<int>{nums1[i], nums2[j]});
            
            if (j + 1 < nums2.size()){
                min_heap.push({i, j + 1});
            }
        }
        return res;
    }
};