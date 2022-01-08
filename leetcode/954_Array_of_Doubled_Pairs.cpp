/******************************************************************************
https://leetcode.com/problems/array-of-doubled-pairs/

1.7.2021
*******************************************************************************/
//use greedy algorithm; it has to be sorted other it may give the wrong answer
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int num : arr){
            m[num]++;
        }
        
        sort(arr.begin(), arr.end(), [](const int num1, const int num2){
            return abs(num1) < abs(num2);
        });
             
        for (const int& num : arr){
            if (m[num] > 0){
                if (m[2 * num] == 0){
                    return false;
                }else{
                    m[num]--;
                    m[2 * num]--;
                }
            }
        }     
        
        return true;
    }
};