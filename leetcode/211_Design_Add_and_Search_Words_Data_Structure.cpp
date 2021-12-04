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
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */