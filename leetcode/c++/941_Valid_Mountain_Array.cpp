/******************************************************************************
https://leetcode.com/problems/valid-mountain-array/

9.11.2021
*******************************************************************************/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() <3){
            return false;
        }
        int left = 0;
        while(left + 1 < arr.size() && arr[left + 1] > arr[left]){
            left++;
        }
        
        int right = arr.size()-1;
        while(right -1 >= 0 && arr[right-1] >arr[right]){
            right--;
        }
        
        return left == right && left > 0 && right < arr.size() -1;
    }
};