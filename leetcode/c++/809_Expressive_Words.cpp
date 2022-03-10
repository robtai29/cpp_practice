/******************************************************************************
https://leetcode.com/problems/expressive-words/

11.26.21
*******************************************************************************/

class Solution {
private:
    int getRepeatLen(const string& s, int index){
        if (index >= s.length()){
            return -1;
        }
        
        int repeat{0};
        char ch = s[index];
        while(index < s.length() && s[index] == ch){
            repeat++;
            index++;
        }
        return repeat;
    }
    
    bool checkStretchy(const string& word1, const string& word2){

        for (int i = 0, j = 0; i < word1.length() && j < word2.length();){
            if (word1[i] != word2[j]){
                return false;
            }
            
            int len1 = getRepeatLen(word1, i);
            int len2 = getRepeatLen(word2, j);

           if (len2 > len1){
                return false;
            }
            if (len1 > len2 && len1 < 3){
                return false;
            }
            
            i += len1;
            j += len2;
            
            if (i == word1.length() && j == word2.length()){
                return true;
            }
        }
        return false;
    }
    
public:
    int expressiveWords(string s, vector<string>& words) {
        int res{0};
        for (string word : words){
            if (checkStretchy(s, word)){
                res++;
            }
        }
        return res;
    }
};

/*
class Solution {
private:
    int getRepeatLen(const string& s, int index){
        if (index > s.length()){
            return -1;
        }
        
        int repeat{0};
        char ch = s[index];
        while(index < s.length() && s[index] == ch){
            repeat++;
            index++;
        }
        return repeat;
    }
    
    void createTable(vector<pair<char, int>>& table, const string& str){
        int index = 0;
        while(index < str.length()){
            int length = getRepeatLen(str, index);
            pair<char, int> p = {str[index], length};
            table.push_back(p);
            index += length;
        }
    }
    
public:
    int expressiveWords(string s, vector<string>& words) {
        int res{0};
        vector<pair<char, int>> stretchTable;
        createTable(stretchTable, s);
        for (string word : words){
            int index = 0;
            int tableIndex = 0;
            while(index < word.length() && tableIndex < stretchTable.size()){
                char stretchChar = stretchTable[tableIndex].first;
                int stretchLen = stretchTable[tableIndex].second;
                char ch = word[index];
                int len = getRepeatLen(word, index);
                if (stretchChar != ch){
                    break;
                }
                if (len > stretchLen){
                    break;
                }
                if (stretchLen > len && stretchLen < 3){
                    break;
                }
                index += len;
                tableIndex++;
            }
            if (tableIndex == stretchTable.size() && index == word.length()){
                res++;
            }
        }
        return res;
    }
};
*/