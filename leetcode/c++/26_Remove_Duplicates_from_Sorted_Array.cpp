/******************************************************************************
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

7.23.2021
*******************************************************************************/

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    
    int slow = 0;
    int fast = 0;
    int size = nums.size();
      
     while (fast < size){
         
         if (nums[slow] == nums[fast]){
             fast++;
             
         }else{
             ++slow;
            nums[slow] = nums[fast];
            fast++;
     }
     }
      nums.erase(begin(nums) + slow + 1, nums.end());
      return nums.size();
  }
};
/*
  int removeDuplicates(vector<int>& nums) {
    
      if (nums.size() == 0){
          return 0;
      }
      int slow = 0;
      for (int fast = 0; fast < nums.size(); fast++){
          if (nums[fast] != nums[slow]){
              slow++;
              nums[slow] = nums[fast];
          }
      }
      return slow + 1;
  }
*/

