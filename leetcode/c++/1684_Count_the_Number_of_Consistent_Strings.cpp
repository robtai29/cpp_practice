/******************************************************************************
https://leetcode.com/problems/count-the-number-of-consistent-strings/

6.18.2021
*******************************************************************************/
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> set;

        for (int i = 0; i < allowed.length(); i++){
            set.insert(allowed[i]);
        }

        int count = words.size();
        for (int i = 0; i < words.size(); i++){
            for (int j = 0; j < words[i].length(); j++){
                char ch = words[i][j];
                if (set.find(ch) == set.end()){
                    --count;
                    break;
                }
            }
            

        }
        return count; 
    }
};