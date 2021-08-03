/******************************************************************************
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

8.3.2021
*******************************************************************************/
//use Kadane's algorithm

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currentMax{0};
        int globalMax{0};
        
        for (int i = 1; i < prices.size(); i++){
            currentMax += prices[i] - prices[i-1];
            currentMax = max(0, currentMax);
            globalMax = max(globalMax, currentMax);
            
        }
        
        return globalMax;
    }
};

