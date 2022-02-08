/******************************************************************************
https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/

2.7.22
*******************************************************************************/

class DisjointSet{
  private:
    int numSets;
    vector<int> root;
    vector<int> rank;
    public:
    DisjointSet(int size) : root(size), rank(size){
        numSets = size;
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
        
        numSets--;
        if (rank[x] > rank[y]){
            root[rootY] = rootX;
        }else if (rank[y] > rank[x]){
            root[rootX] = rootY;
        }else{
            root[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    int getNumSets(){
        return numSets;
    }

};

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end(), [](auto& log1, auto& log2){
           return log1[0] < log2[0]; 
        });
        
        DisjointSet s(n);
        for (auto& log : logs){
            int time = log[0];
            int a = log[1];
            int b = log[2];
            
            s.unionSet(a, b);
            if (s.getNumSets() == 1){
                return time;
            }
        }
        return -1;
    }
};