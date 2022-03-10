/******************************************************************************
https://leetcode.com/problems/rank-transform-of-an-array/

6.27.2021
*******************************************************************************/
class Solution {
public:
vector<int> arrayRankTransform(vector<int>& arr) {
	map<int, int> map;
    
    for (int num : arr){
        map[num] = 0;
    }
    
    int rank = 1;
    for (auto& entry : map){
            entry.second = rank++;
    }
    
    vector<int> result;
    
    for (int num : arr){
        rank = map[num];
        result.push_back(rank);
        
    }
    
    return result;
}
};