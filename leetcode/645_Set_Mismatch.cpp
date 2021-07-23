/******************************************************************************
https://leetcode.com/problems/set-mismatch/

7.22.21
*******************************************************************************/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        vector<int> res{0, 0};
        vector<int> number(nums.size() + 1, -1);
        
        for (int num : nums){
            if (number[num] == 1){
                res[0] = num;
            }else{
                number[num] = 1;
            }
        }
        
        number[0] = 1;
        
        for (int i = 0; i < number.size(); i++){
            if (number[i] == -1){
                res[1] = i;
            }
        }
        return res;
    }
};