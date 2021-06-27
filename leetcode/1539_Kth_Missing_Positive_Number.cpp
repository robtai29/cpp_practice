/******************************************************************************
https://leetcode.com/problems/kth-missing-positive-number/

6.26.2021
*******************************************************************************/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int index = 0;
        int num = arr[index];
        for (int i = 1; i <= 10000; i++){
             if (index < arr.size()){
                 num = arr[index];
                 }
            
                 if (num == i){
                     index++;
                     
                 }else{
                 
             
                 k--;
                 
                 if ( k == 0){
                     return i;
                 }
                 
             }
            
            
        }
        return -1;
    }
};

/*
Another solution
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for (auto a : arr) if (a <= k) k++;
        return k;
    }
};

*/
