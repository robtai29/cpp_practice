/******************************************************************************
https://leetcode.com/problems/add-binary/

9.23.2021
*******************************************************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        
        int carryover{0};
        
        for (int i = a.size() -1, j = b.size()-1; j>= 0 || i >= 0;i--, j--){
            int numA = i >= 0 ? a[i] -'0' : 0;
            int numB = j >= 0 ? b[j] -'0': 0;
            
            int sum = numA + numB + carryover;
            carryover = sum / 2;
            int mod = sum % 2;
            res.push_back(mod + '0');
        }
        
        if (carryover == 1){
            res.push_back(1 + '0');
        }
        
        reverse(begin(res), end(res));        
        return res;
    }
};