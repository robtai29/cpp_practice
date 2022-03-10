/******************************************************************************
https://leetcode.com/problems/k-closest-points-to-origin/

2.18.2022
*******************************************************************************/

//max heap nlogk

class Solution {
private:
    struct compare{
      bool operator()(vector<int>& p, vector<int>& q){
          return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
      }  
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        
        priority_queue< vector<int>, vector<vector<int>>, compare> pq;
        
        for (auto& point : points){
            pq.push(point);
            if (pq.size() > k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
            return res;
    }
};