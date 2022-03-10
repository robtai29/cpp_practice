/******************************************************************************
https://leetcode.com/problems/happy-number/

2.27.22
*******************************************************************************/

class Solution {
private:
    int next(int n){
        int res = 0;
        while (n > 0){
            int mod = n % 10;
            res += mod * mod;
            n = n / 10;
        }
            return res;
    }   
public:
    bool isHappy(int n) {
        int turtle = next(n);
        int hare = next(next(n));
        
        while (turtle != hare){
            turtle = next(turtle);
            hare = next(next(hare));
            
        }
            return turtle ==1;
    }
};