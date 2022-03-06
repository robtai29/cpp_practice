/******************************************************************************
https://leetcode.com/problems/hamming-distance/

2.25.2022
*******************************************************************************/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count{0};
        
        while (n > 0){
            count += n & 1;
            n >>= 1;
        }
            return count;
    }
};

/*
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count{0};
        
        while (x > 0 || y > 0){
            int xDigit = x % 2;
            int yDigit = y % 2;
            
            count += xDigit ^ yDigit;
            x = x >> 1;
            y = y >> 1;   
        }
            return count;
    }
};
*/