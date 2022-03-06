/******************************************************************************
https://leetcode.com/problems/zigzag-conversion/

3.6.2022
*******************************************************************************/
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> list(numRows);
        
        bool down = true;
        int line = 0;
        for (int i = 0; i < s.size(); i++){
            
            if (down == true){
                list[line].push_back(s[i]);
                line++;
                if (line == numRows){
                    down = false;
                    line = line - 2 >= 0 ? line -2 : 0;
                    
                }
            }else{
                list[line].push_back(s[i]);
                line--;
                 if (line == -1){
                    down = true;
                    line = line +2 < numRows ? line + 2 : 0;
                    
                }
            }
        }
        
        string res;
        for (string str : list){
            res += str;
        }
        return res;
    }
};

/*
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> lines(numRows);
        int n = s.length();
        for (int i = 0; i < n; ){
            for (int j = 0; i < n && j < numRows; j++, i++){
                lines[j].push_back(s[i]);

            }
            
            for (int j = numRows-2; i < n && j >= 1; j--, i++){
                lines[j].push_back(s[i]);

            }
        }
        
        string res;
        
        for (string line : lines){
            res += line;
        }
        
        return res;
    }
};
*/