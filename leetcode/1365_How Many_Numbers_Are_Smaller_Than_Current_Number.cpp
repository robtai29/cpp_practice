class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> preSum(101, 0);
        vector<int> result(nums.size(), 0);
        
        for (int i = 0; i < nums.size(); i++){
            preSum[nums[i]]++;
        }
        

        
        int sum = 0;
        for (int i = 0; i < preSum.size(); i++){
            
           sum += preSum[i];
            preSum[i] = sum;
            
        }
        
        for (int i = 0; i < nums.size(); i++){
            
            int val = nums[i];
            val == 0 ?  result[i] = 0 : result[i] = preSum[val - 1];
            
        }
        
        return result;
        
    }
};