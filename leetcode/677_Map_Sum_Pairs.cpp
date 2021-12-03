/******************************************************************************
https://leetcode.com/problems/map-sum-pairs/

11.30.21
*******************************************************************************/

class MapSum {
private:
    unordered_map<string, int> m;
    struct TrieNode{
      int sum = 0;
      TrieNode* array[26] = {};
    };
    
    TrieNode* root;
    
public:
    MapSum() {
        root = new TrieNode;
    }
    
    void insert(string key, int val) {
        int prevValue = m[key];
        m[key] = val;
        TrieNode* current = root;
        for (char ch : key){
            if (current -> array[ch - 'a'] == nullptr){
                current -> array[ch - 'a'] = new TrieNode;
            }
            current = current -> array[ch - 'a'];
            current -> sum = current -> sum - prevValue + val;
        }
    }
    
    int sum(string prefix) {
        TrieNode* current = root;
        for (char ch : prefix){
                if (current -> array[ch - 'a'] == nullptr){
                return 0;
            }
            current = current -> array[ch - 'a'];
        }
        return current -> sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
