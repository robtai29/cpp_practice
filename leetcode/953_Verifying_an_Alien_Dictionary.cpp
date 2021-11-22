/******************************************************************************
https://leetcode.com/problems/verifying-an-alien-dictionary/

11.21.2021
*******************************************************************************/

class Solution {
private:
    int compare(const string& a, const string& b, const vector<int>& letterOrder){
        for (int i = 0, j = 0; i < a.size() || j < b.size(); i++, j++){
            int aValue = i < a.size() ? letterOrder[a[i] - 'a'] : -1;
            int bValue = j < b.size() ? letterOrder[b[j] - 'a'] : -1;
            if (aValue > bValue){
                return 1;
            }else if (aValue < bValue){
                return -1;
            }
        }
        return 0;
    }

public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> letterOrder(26, 0);
        
        for (int i = 0; i < order.size(); i++){
            int index = order[i] - 'a';
            letterOrder[index] = i;
        }
        
        for (int i = 0; i+1 < words.size(); i++){
            if (compare(words[i], words[i+1], letterOrder) == 1){
                return false;
            }     
        }
        return true;
    }
};