/******************************************************************************
https://leetcode.com/problems/sorting-the-sentence/

6.20.21
*******************************************************************************/

class Solution {
public:
    string sortSentence(string s) {
        vector<string> v(10, "");
        int wordBegin = 0;
        int wordSize = 0;
        
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ' ' || i == s.length()-1){
                int index = 0;
                
                if (i < s.length()-1){
                    index = s[i-1] - '0';
                    wordSize--;
                }else{
                    index = s[i] - '0';
                }
                
            
                
                string str = s.substr(wordBegin, wordSize);
                v[index] = str;
                wordBegin = i + 1;
                wordSize = 0;
            }else{
                wordSize++;
            }
    }
        string result;

        for (int i = 0; i < v.size(); i++){
            if (v[i].length() > 0){
                result += v[i] + " ";
            }
        }
        
  
        result.erase(result.length()-1);
        
        
        return result;
    }
};