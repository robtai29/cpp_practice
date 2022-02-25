/******************************************************************************
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

11.27.2021
*******************************************************************************/

class Solution {
private:
    int lowerbound(vector<int>& nums, int target){
        //lowerbound return index of the first number greater or equal to the target
        int low = 0;
        int high = nums.size() -1;
        while (low < high){
            int mid = low + (high - low) /2;
            if (nums[mid] < target){
                low = mid + 1;
            }else{
                //nums[mid] >= target
                high = mid;
            }
        }
        return low;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return {-1, -1};
        }
        int low = lowerbound(nums, target);
        int high = lowerbound(nums, target +1);
        vector<int> res(2, -1);
        
        //check to make sure target is found;
        if (nums[low] != target){
            return res;
        }
        
        res[0] = low;
        res[1] = nums[high] > target ? high -1 : high;
        return res;
    }
};

/*
    //method 1
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return {-1, -1};
        }
        int low = 0;
        int high = nums.size() -1;
        vector<int> res(2, -1);
        
        while (low < high){
            int mid = low + (high - low) / 2;
            if (target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        
        if (nums[low] != target){
            return res;
        }else{
            res[0] = low;
        }
        
        target += 1;
        high = nums.size() -1;
         while (low < high){
            int mid = low + (high - low) / 2;
            if (target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        
        res[1] = nums[low] == target -1 ? low : low -1;
        return res;
    }
*/

/*
//STl
// lower bound return index of first number not less than target

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto itr = lower_bound(nums.begin(), nums.end(), target);
        int index = itr - nums.begin();
        if (itr == nums.end() || *itr != target){
            return {-1, -1};
        }
        
        vector<int> res;
        res.push_back(index);
        itr = lower_bound(nums.begin(), nums.end(), target + 1);
        index = itr - nums.begin() -1;
        res.push_back(index);
        return res;
        
    }
};
*/