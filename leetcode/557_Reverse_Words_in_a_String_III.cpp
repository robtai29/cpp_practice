/******************************************************************************
https://leetcode.com/problems/reverse-words-in-a-string-iii/

12.26.21
*******************************************************************************/
class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.length(); j++){
            if (s[j] == ' ' || j == s.length() -1){
                j == s.length() -1 ? reverse(s.begin() + i, s.end()) : reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
            
        }
            return s;
    }
};

/*
    string reverseWords(string s) {
        
        int right = s.find(' ');
        int left = 0;
        while (right != string::npos){
            reverse(s.begin() + left, s.begin() + right);
            left = right + 1;
            right = s.find(' ', right + 1);
        }
        
        reverse(s.begin() + left, s.end());
        return s;
    }
*/

/*
class Solution {
    void reverseWords(string& str, int start, int end){
        int len = end - start + 1;
        while (start < end){
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }
    
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        
        for (int i = 0; i < s.length(); i++){
            if (s[i] == ' ' || i == s.length() -1){
                end = i == s.length() -1 ? i : i-1;
                reverseWords(s, start, end);
                start = i + 1;
            }
        }
        return s;
    }
};
*/