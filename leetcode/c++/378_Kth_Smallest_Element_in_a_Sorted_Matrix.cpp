/******************************************************************************
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

2.20.2022
*******************************************************************************/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        auto comp = [&matrix](pair<int, int> p1, pair<int, int> p2){
            return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        int n = matrix.size();

        for (int j = 0; j < n; j++){
            min_heap.push({0, j});
        }
        
        while (k-- > 1 && !min_heap.empty()){
            
            int i = min_heap.top().first;
            int j = min_heap.top().second;
            min_heap.pop();
            
            if (i+1 < n && j < n){
                min_heap.push({i+1, j});
            }
        }
        int r = min_heap.top().first;
        int c = min_heap.top().second;
        return matrix[r][c];
    }
};