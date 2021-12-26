/******************************************************************************
https://leetcode.com/problems/3sum/

12.5.2021
*******************************************************************************/

class Solution {
public:
/*
sort the vector
set up 3 pointers, i, j, k to see nums[i], nums[j], and nums[k] add up to 0.
iterate i through a loop. j = i +1. k = nums.size() -1. two pointers
add triple of values to res vector if sum is 0.
after than, move j through duplicate values of nums[j] and move k through duplicates value of nums[k]
after a loop, move i through duplicate values of nums[i] to prevent duplicate values added to the result

*/
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 3){
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ){
            int target = -nums[i];
            int left = i + 1;
            int right = n -1;
            
            while (right > left){
                int sum = nums[left] + nums[right];
                if (sum > target){
                    right--;
                    
                }else if (sum < target){
                    left++;
                }else{
                    //target == sum
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    res.push_back(triplet);
                    
                    //skip all the duplicates
                    while(left < n && nums[left] == triplet[1]){
                        left++;
                    }
                    
                    while(right >= 0 && nums[right] == triplet[2]){
                        right--;
                    }
                }
            }
            //skip all duplicates of nums[i];
            int startVal = nums[i];
            while(i < n && nums[i] == startVal){
                i++;
            }
        }
        return res;      
    }
};