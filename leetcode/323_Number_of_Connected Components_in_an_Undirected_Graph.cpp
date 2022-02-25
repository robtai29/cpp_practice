/*************************************************************************
https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

2.7.2022
**************************************************************************/

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
      
      x = find(root[x]);
      return x;
  }
    
    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY){
            return;
        }
        numSets--;
        if (rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
        }else if (rank[rootY] > rank[rootX]){
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

class Solution{
public:
  int countComponents(int n, vector<vector<int>> edges){
      DisjointSet d1(n);
      for (const auto& edge : edges){
          d1.unionSet(edge[0], edge[1]);
      }
        return d1.getNumSets();  
  }  
};