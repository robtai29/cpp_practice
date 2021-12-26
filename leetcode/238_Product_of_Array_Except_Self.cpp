/******************************************************************************
https://leetcode.com/problems/product-of-array-except-self/

12.5.2021
*******************************************************************************/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
	left[0] = 1;
	for (int i = 1; i < nums.size(); i++){
		left[i] = left[i-1] * nums[i-1];
	}
	int right = 1;
	
	for (int j = nums.size() -1; j >= 0; j--){
		left[j] = left[j] * right;
		right = right * nums[j];
	}
	    return left;        
    }
};