/******************************************************************************
https://leetcode.com/problems/search-insert-position/

6.17.21
*******************************************************************************/

#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(begin(nums), end(nums), target);
        return distance(begin(nums), it);

    }

    int searchInsert1(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() -1;
        
        while (left < right){
            int middle = left + (right - left ) / 2;

            if (nums[middle] == target){
                return middle;
            }else if (nums[middle] > target){
                right = middle -1;
            }else{
                left = middle + 1;
            }
            
        }

        return left;


    }


};