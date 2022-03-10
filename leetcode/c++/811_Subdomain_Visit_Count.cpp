/******************************************************************************
https://leetcode.com/problems/subdomain-visit-count/

11.26.21
*******************************************************************************/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (string domain: cpdomains){
            int index = domain.find(" ");
            int num = stoi(domain.substr(0, index));
            index++;
            string name = domain.substr(index);
            m[name] += num;
            
            for (int i = 0; i < domain.length(); i++){
                if (domain[i] == '.'){
                    m[domain.substr(i + 1)] += num;
                }
            }
        }
            vector<string> res;
            for (const auto& entry : m){
                string str = to_string(entry.second) + " " + entry.first;
                res.push_back(str);
            }
        return res;
    }
};