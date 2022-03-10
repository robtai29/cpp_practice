/*************************************************************************
https://leetcode.com/problems/graph-valid-tree/

2.6.2022
**************************************************************************/


class DisjointSet{
private: 
vector<int> root;

public:
DisjointSet(int size) : root(size){
    for (int i = 0; i < size; i++){
        root[i] = i;
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

 root[rootY] = rootX;
}

bool connected(int x, int y){
    return find(x) == find(y);
}

};


class Solution {
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        if (n-1 != edges.size()){
            return false;
        }

        DisjointSet d1(n);

        for (const auto& edge : edges){
            int rootA = d1.find(edge[0]);
            int rootB = d1.find(edge[1]);

            if (rootA == rootB){
                return false;
            }

            d1.unionSet(edge[0], edge[1]);
        }

        return true;
    }
};