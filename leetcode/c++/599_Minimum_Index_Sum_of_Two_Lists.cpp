/******************************************************************************
https://leetcode.com/problems/minimum-index-sum-of-two-lists/

9.6.21
*******************************************************************************/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> m;
        
        for (int i = 0; i < list1.size(); i++){
            
            auto itr = find(begin(list2), end(list2), list1[i]);
            if (itr != end(list2)){
                int index = distance(begin(list2), itr) + i;
                m[list1[i]] = index;
            }
        }
        int smallest = begin(m) -> second;
        for (auto ptr = begin(m); ptr != end(m); ptr++){
            if (smallest > ptr -> second){
                smallest = ptr -> second;

            }
        }
        
        vector<string> res;
        
        for (auto entry : m){
            if (entry.second == smallest){
                res.push_back(entry.first);
            }
        }
        
        return res;

    }
};
/*
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<int, vector<string>> m;
        
        for (int i = 0; i < list1.size(); i++){
            
            auto itr = find(begin(list2), end(list2), list1[i]);
            if (itr != end(list2)){
                int index = distance(begin(list2), itr) + i;
                m[index].push_back(list1[i]);
            }
        }
           
        return begin(m)-> second;
        
    }
};
*/