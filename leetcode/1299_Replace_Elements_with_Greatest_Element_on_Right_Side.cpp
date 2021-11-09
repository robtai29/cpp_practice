/******************************************************************************
https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

11.9.2021
*******************************************************************************/

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //in place modifyig the input array;
        int maxRight = -1;
        int prev = INT_MIN;
        int n = arr.size();
        for (int i = n-1; i >= 0; i--){
            maxRight = max(maxRight, prev);
            prev = arr[i];
            arr[i] = maxRight;
        }
        return arr;
    }
};

/*
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res(arr);
        int n = arr.size();
        
        res[n-1] = -1;
        for (int i = n-2; i >= 0; i--){
            res[i] = max(res[i+1], arr[i+1]);
        }
        return res;
    }
*/
