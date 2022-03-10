/******************************************************************************
https://leetcode.com/problems/flipping-an-image/

9.5.21
*******************************************************************************/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto& v: image){
                int left = 0;
                int right = v.size()-1;
                while (right >= left){
                    if (v[right] == v[left]){
                        v[right] = v[left] = v[left] ^ 1;
                    }
                    right--;
                    left++;
                }
            }
        return image;
            
        }