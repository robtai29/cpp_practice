/******************************************************************************
https://leetcode.com/problems/reverse-prefix-of-word/

9.24.2021
*******************************************************************************/

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = 0;
        for (int i = 0; i < word.size(); i++){
            if (word[i] == ch){
                index = i;
                break;
            }
            
        }
        
        if (index > word.size()){
            return word;
        }
        
        //swap
        string res(word);
        for (int i = 0; i <= index/2; i++){
            swap(res[i], res[index - i]);
        }
        
        return res;
        
    }
};
/*
    string reversePrefix(string word, char ch) {
        string res(word);
        size_t index = word.find(ch);
        reverse(begin(res), begin(res) + index +1);
        return res;
    }
*/