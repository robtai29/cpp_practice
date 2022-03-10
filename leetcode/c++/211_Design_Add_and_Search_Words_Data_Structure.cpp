/******************************************************************************
https://leetcode.com/problems/design-add-and-search-words-data-structure/

12.4.2021
*******************************************************************************/

class WordDictionary{
    private:
        struct TrieNode{
            TrieNode* array[26] = {};
            bool isWord = false;
        };
        TrieNode* root;
    
    public:
        WordDictionary(){
            root = new TrieNode();
        }
    
        void addWord(string word) {
            TrieNode* current = root;
            for (char ch : word){
                if (current -> array[ch - 'a'] == nullptr){
                    current -> array[ch - 'a'] = new TrieNode;
                }
                current = current -> array[ch - 'a'];
            }
            
            current -> isWord = true;
        }
    
        bool search(string word) {
            return search(word, 0, root);
        }
    
        bool search(const string& word, int index, TrieNode* ptr){
            if (index == word.length()){
                return ptr -> isWord;
            }
            
            if (word[index] == '.'){
                for (int i = 0; i < 26; i++){
                    if (ptr -> array[i] && search(word, index + 1, ptr -> array[i])){
                        return true;
                    }
                }
            }else{
                return ptr -> array[word[index] - 'a'] && search(word, index + 1, ptr -> array[word[index] - 'a']);
            }
            return false;
        }
};


/**
class WordDictionary {
private:
    struct TrieNode{
        unordered_map<char, TrieNode*> mp;
        bool isWord = false;
    };
        TrieNode* root = nullptr;
    
    bool search(const string& word, TrieNode* current, int index){
        if (index == word.length()){
            return current -> isWord;
        }
        
        if (word[index] == '.'){
                for (auto itr = current-> mp.begin(); itr != current -> mp.end(); ++itr){
                    if (search(word, itr -> second, index + 1)){
                        return true;
                    }
                
            }
        }else if (current -> mp.count(word[index]) == 1){
            return search(word, current -> mp[word[index]], index + 1);
        }
            return false;
    }

    
public:
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode* current = root;
        
        for (const char& ch : word){
            if (current -> mp.count(ch) == 0){
                current -> mp[ch] = new TrieNode;
            }
                current = current -> mp[ch];
        }
                current -> isWord = true;
    }
    
    bool search(string word) {
        
        return search(word, root, 0);
        
    }
};

 */