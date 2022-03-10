/******************************************************************************
https://leetcode.com/problems/implement-trie-prefix-tree/

10.8.2021
*******************************************************************************/
class Trie {
private:
    Trie* next[26] = {};
    bool isword = false;
public:
    Trie() {
    }

    void insert(string word) {
        Trie* node = this;
        for (char ch : word){
            int pos = ch - 'a';
            if (node-> next[pos] == nullptr){
                node-> next[pos] = new Trie;
            }
            node = node -> next[pos];
        }
        node-> isword = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char ch : word){
            int pos = ch - 'a';
            if (node-> next[pos] == nullptr){
                return false;
            }
            node = node -> next[pos];
        }
        return node-> isword;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix){
            int pos = ch - 'a';
            if (node-> next[pos] == nullptr){
                return false;
            }
            node = node -> next[pos];
        }
        return true;
    }
};
/*
class Trie {
public:
    Trie() {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (node->next.count(ch) == 0) { node-> next[ch] = new Trie(); }
            node = node->next[ch];
        }
        node->isword = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (!node->next.count(ch)) { return false; }
            node = node->next[ch];
        }
        return node->isword;
    }
    
  bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            if (!node->next.count(ch)) { return false; }
            node = node->next[ch];
        }
        return true;
    }

private:
    map<char, Trie*> next ={};
    bool isword = false;
};
*/