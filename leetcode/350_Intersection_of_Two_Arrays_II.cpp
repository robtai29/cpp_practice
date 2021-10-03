/******************************************************************************
https://leetcode.com/problems/intersection-of-two-arrays-ii/

9.24.2021
*******************************************************************************/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int v[1001]{0};
        vector<int> result;
        
        for (int num : nums1){
            v[num]++;
        }
        
        for (int num : nums2){
            if (v[num] > 0){
                v[num]--;
                result.push_back(num);
            }
        }
        return result;
    }
};