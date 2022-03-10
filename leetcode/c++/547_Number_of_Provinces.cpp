/************************************************************************
https://leetcode.com/problems/number-of-provinces/

2.6.2022
************************************************************************/

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
    
    //path compression
    int find(int x){
        if (x == root[x]){
            return x;
        }
        
        x = find(root[x]);
        return x;
    }
    
    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY){
            return;
        }
        
        if (rank[rootX] > rank[rootY]){
            root[rootY] = root[rootX]; 
        }else if (rank[rootY] > rank[rootX]){
            root[rootX] = root[rootY];
        }else{
             root[rootY] = root[rootX];
             rank[rootX]++;
        }
    }
    
    bool connected(int x, int y){
        return find(x) == find(y);
    }
    
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet d1(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(i != j && isConnected[i][j]){
                    d1.unionSet(i, j);
                }
            }
        }
        
        unordered_set<int> s;
        for (int i = 0; i < n; i++){
            int root = d1.find(i);
            s.insert(root);
        }
        
        return s.size();
    }
};

/*
class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz), count(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }

private:
    vector<int> root;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.size() == 0) {
            return 0;
        }
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    uf.unionSet(i, j);
                }
            }
        }
        return uf.getCount();
    }
};
*/