/******************************************************************************
https://leetcode.com/problems/smallest-string-with-swaps/

2.7.22
*******************************************************************************/

class DisjointSet{
  private:
    vector<int> root;
    vector<int> rank;
    public:
    DisjointSet(int size) : root(size), rank(size){
        for (int i = 0; i < size; i++){
            root[i] = i;
            rank[i] = 1;
        }
        
    }
    
    int find(int x){
        if (x == root[x]){
            return x;
        }
        
        root[x] = find(root[x]);
        return root[x];
    }
    
    void unionSet(int x, int y){
        int rootY = find(y);
        int rootX = find(x);
        
        if (rootY == rootX){
            return;
        }
        
        if (rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
        }else if (rank[rootY] > rank[rootX]){
            root[rootX] = rootY;
        }else{
            root[rootY] = rootX;
            rank[rootX]++;
        }
    }

};




class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        DisjointSet s1(n);
        for (auto& pair_ : pairs){
            s1.unionSet(pair_[0], pair_[1]);
        }
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m; 
        for (int i = 0; i < n; i++){
            int root = s1.find(i);
            char ch = s[i];
            
            m[root].push(ch);
        }
        
        string res(n, ' ');
        
        for (int i = 0; i < n; i++){
            int index = s1.find(i);
            char ch = m[index].top();
            m[index].pop();
            res[i] = ch;
        }
        
        return res;
    }
};
