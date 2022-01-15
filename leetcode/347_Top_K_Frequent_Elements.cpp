class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        
        unordered_map<int, int> counter;
        for (int num : nums){
            counter[num]++;
        }
        
        for (auto& entry : counter){
            pq.push({entry.second, entry.first});
        }
        
        vector<int> res;
        for (int i = 0; i < k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};

/*
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //use bucket sort
        
        unordered_map<int, int> freq;
        for (int num : nums){
            freq[num]++;
        }
        
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& entry : freq){
            int num = entry.first;
            int count = entry.second;
            buckets[count].push_back(num);
        }
        
        vector<int> res;
        int counter = 0;
        
        for (int i = buckets.size() -1; i >= 0; i--){
            for (int j = 0; j < buckets[i].size() && counter < k; j++){
                res.push_back(buckets[i][j]);
                counter++;
            }
        }
            return res;      
    }
};
*/