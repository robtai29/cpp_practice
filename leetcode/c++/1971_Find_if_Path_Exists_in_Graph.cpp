/******************************************************************************
https://leetcode.com/problems/largest-odd-number-in-string/

9.26.2021
*******************************************************************************/

class Solution {
public:
    vector<int> parent;
    
    int root(int node){
        if (parent[node] == node){
            return node;
        }
        
        return root(parent[node]);
    }
    
    void quickUnion(int v1, int v2){
        int root1 = root(v1);
        int root2 = root(v2);
        
        if (root1 > root2){
            parent[root2] = root1;
        }else{
            parent[root1] = root2;
        }
    }
  
 bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
     parent.resize(n);
     for (int i = 0; i < n; i++){
         parent[i] = i;
     }
     
     for (auto& pair : edges){
         quickUnion(pair[0], pair[1]);
     }
     
     return root(start) == root(end);
        
    }
};

    //bfs
    /*
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int current = q.front();
            q.pop();
            if (current == end){
                return 1;
            }

            visited[current] = true;
            
            vector<int>& neighbors = graph[current];
            for (int neighbor : neighbors){
                if (visited[neighbor] == false)
                q.push(neighbor);
            }
            
        }
            return false;     
        
    }
    */