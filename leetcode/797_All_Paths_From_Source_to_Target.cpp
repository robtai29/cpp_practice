/******************************************************************************
https://leetcode.com/problems/all-paths-from-source-to-target/

2.8.22
*******************************************************************************/

class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& path, vector<vector<int>>& graph, int current){
        int n = graph.size();
        if (current == n -1){
            res.push_back(path);
            return;
        }
        
        for (int neighbor : graph[current]){
            path.push_back(neighbor);
            dfs(res, path, graph, neighbor);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        path.push_back(0);
        
        dfs(res, path, graph, 0);
        return res;
    }
};

/*
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        int n = graph.size();        
        queue<pair<int, vector<int>>> q;
        q.push({0, vector<int>{0}});
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                int current = q.front().first; 
                vector<int> path =  q.front().second;
                if (current == n -1){
                    res.push_back(path);
                }
                
                q.pop();
                for (int neighbor : graph[current]){
                    path.push_back(neighbor);
                    q.push({neighbor, path});
                    path.pop_back();
                }
            }
        }        
        return res;

    }
};
*/
