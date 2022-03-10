/******************************************************************************
https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

6.20.2021
*******************************************************************************/

class Solution {
public:
    string freqAlphabets(string s) {
        stringstream ss;
        for (int i = 0; i < s.length(); i++){

            if (i+2 < s.length() && s[i+2] == '#'){
                int num = stoi(s.substr(i, 2));
                char ch = num + 96;
                ss << ch;
                i= i+2;
                
            }else{
                int num = stoi(s.substr(i, 1));
                char ch = num + 96;
                ss << ch;
                
            }
            
        }
        return ss.str();
    }
};