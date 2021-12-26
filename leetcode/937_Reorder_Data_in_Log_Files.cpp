/******************************************************************************
https://leetcode.com/problems/reorder-data-in-log-files/submissions/

12.25.2021
*******************************************************************************/

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digits;
        vector<pair<string, string>> letters;
        
        for (const string& log : logs){
            int index = log.find(' ');
            if (isdigit(log[index + 1])){
                digits.push_back(log);
            }else{
                string content = log.substr(index + 1);
                string identifier = log.substr(0, index);
                letters.push_back({content, identifier});
            }
        }
        
        sort(letters.begin(), letters.end(), [](auto& p1, auto& p2){
            return p1.first == p2.first ? p1.second < p2.second : p1.first < p2.first;
        });
            
        vector<string> res;
        for (const auto& p : letters){
            res.push_back(p.second + " " + p.first);
        }
        
        res.insert(res.end(), digits.begin(), digits.end());
        return res;
    }
};