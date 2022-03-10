/******************************************************************************
https://leetcode.com/problems/find-common-characters/

6.26.21
*******************************************************************************/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int arr[26]{0};
        
        for (char ch : words[0]){
            int index = ch - 'a';
            arr[index]++;
        }
        
        for (int i = 1; i < words.size(); i++){
            int temp[26]{0};
            for (char ch : words[i]){
                
                int index = ch - 'a';
                temp[index]++;
            }
            
            for (int i = 0; i < 26; i++){
                arr[i] = min(arr[i], temp[i]); 
            }
        }
        
        vector<string>result;
        
        for (int i = 0; i < 26; i++){
            int count = arr[i];
            while (count > 0){
                char ch = i + 'a';
                string s;
                s = ch;
                result.push_back(s);
                count--;
            }
        }
        return result;
    }
};