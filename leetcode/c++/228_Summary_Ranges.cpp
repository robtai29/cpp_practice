/******************************************************************************
https://leetcode.com/problems/summary-ranges/

9.5.2021
*******************************************************************************/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        for (int i = 0; i < nums.size(); ){
            string str;
            
            int ahead = i + 1;
            while(ahead < nums.size() && nums[ahead] == nums[ahead-1] +1){
                ahead++;
            }
            
            if (ahead-1 > i){
                str += to_string(nums[i]) + "->" + to_string(nums[ahead-1]);
            }else{
                str += to_string(nums[i]);
            }
            res.push_back(str);
            i = ahead;

        
    }
     return res;   
    }
        
};