/******************************************************************************
https://leetcode.com/problems/longest-consecutive-sequence/

1.6.2022
*******************************************************************************/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (const int& num : nums){
            s.insert(num);
        }
        
        int res{0};
        for (int num : nums){
            if (s.find(num) != s.end()){
                s.erase(num);
                int left = num -1;
                int right = num + 1;
                while (s.find(left) != s.end()){
                    s.erase(left);
                    left--;
                }
                
                while(s.find(right) != s.end()){
                    s.erase(right);
                    right++;
                }
                
                res = max(res, right - left - 1);
            }
        }
        return res;
    }
};