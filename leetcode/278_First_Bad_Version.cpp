/******************************************************************************
https://leetcode.com/problems/first-bad-version/

10.31.2021
*******************************************************************************/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        
        while (left < right){
            int mid = left + (right - left)/ 2;
            if (isBadVersion(mid) == false){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        
        return left;
    }
};