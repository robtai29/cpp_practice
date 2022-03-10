/******************************************************************************
https://leetcode.com/problems/most-common-word/

9.28.21
*******************************************************************************/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
    for (auto & c: paragraph){
        if (isalpha(c)){
            c = tolower(c);
        }else{
            c = ' ';
        }
    }
        unordered_map<string, int> map;
        
        for (string str : banned){
            map[str] = -1;
        }
        stringstream ss(paragraph);
        string input;
        string output;
        int largest = -1;
        while (ss >> input){
            if (map[input] != -1){
                map[input]++;

                if (map[input] > largest){
                    largest = map[input];
                    output = input;
                }
            }
        }
        return output;
    }
};