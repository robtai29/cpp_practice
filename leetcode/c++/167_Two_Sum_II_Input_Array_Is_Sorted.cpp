/******************************************************************************
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

11.1.2021
*******************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() -1;
        vector<int> result;
        
        while (left < right){
            int sum = numbers[left] + numbers[right];
            
            if (sum == target){
                break;
            }else if (sum < target){
                left++;
                
            }else{
                right--;
            }
        }

        result.push_back(left+ 1);
        result.push_back(right+ 1);
        
        return result;

    }
};