/******************************************************************************
https://leetcode.com/problems/power-of-two/

10.3.2021
*******************************************************************************/

class Solution {
public:
    bool isPowerOfTwo(int n) {

        return n > 0 && (n & (n -1)) == 0;
    }
};

/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n && ceil(log2(n)) == floor(log2(n));
    }
};
*/