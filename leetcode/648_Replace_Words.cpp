/******************************************************************************
https://leetcode.com/problems/replace-words/

12.2.21
*******************************************************************************/

/*
1. build a trie class. Key method 1: void buildTrie(vector<string>& dictionary)
   to insert all the roots, skip when a root has a root that has been enter before
   keymethod 2: string getRoot(string str)
2. iterator through sentence and build up a string with new roots if possible
*/

class Trie{
  private:
    struct TrieNode{
      TrieNode* array[26] = {};
      bool isWord = false;
    };
    
    TrieNode* root = new TrieNode;
    public:
    void buildTrie(const vector<string>& dictionary){
        
        for (string word : dictionary){
            TrieNode* current = root;
            for (char ch : word){
                if (current -> array[ch - 'a'] == nullptr){
                    current -> array[ch - 'a'] = new TrieNode;
                }
                
                current = current -> array[ch - 'a'];
                if (current -> isWord == true){
                    break;
                }
             }
            
            if (current -> isWord == false){
                current -> isWord = true;
            }
        }
    }
    
    string getRoot(const string& word){
        TrieNode* current = root;
        string res;
        for (char ch : word){
            if (current -> array[ch - 'a'] == nullptr){
                break;
            }
            
            current = current -> array[ch - 'a'];
            res.push_back(ch);
            if (current -> isWord == true){
                return res;
            }
        }
        
        return word;
    }
};


class Solution {
    
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t1;
        t1.buildTrie(dictionary);
        
        stringstream ss(sentence);
        string res;
        
        string word;
        while(ss >> word){
            word = t1.getRoot(word);
            res += word + " ";
        }
        
        res.erase(res.end() -1);
        return res;
    }
};