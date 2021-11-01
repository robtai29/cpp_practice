/******************************************************************************
https://leetcode.com/problems/first-bad-version/

10.31.2021
*******************************************************************************/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        
        int mid = (high - low) / 2 + low;
        
        while(low <= high){
            mid = (high - low) / 2 + low;
            bool isBad = isBadVersion(mid);
            if (isBad){
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        
        return low;
    }
};