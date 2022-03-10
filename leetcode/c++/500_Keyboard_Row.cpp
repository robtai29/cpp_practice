/******************************************************************************
https://leetcode.com/problems/keyboard-row/

11.20.2021
*******************************************************************************/

class Solution {
private:
    bool checkValid(const string& str, const vector<unordered_set<char>>& vects){
        for (const auto& vect_ : vects){
            bool flag = true;
            for (const char& ch : str){
                if (vect_.count(tolower(ch)) == 0){
                    flag = false;
                    break;                   
                }
            }
            
            if (flag){
            return true;
            }
        }
        return false;
    }
    
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        unordered_set<char> row1{'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2{'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3{'z','x','c','v','b','n','m'};

        vector<unordered_set<char>> v = {row1, row2, row3};
        for (string word : words){
        
        bool isValid = checkValid(word, v);
        if (isValid){
            res.push_back(word);
            }
        }
        return res;
    }
};