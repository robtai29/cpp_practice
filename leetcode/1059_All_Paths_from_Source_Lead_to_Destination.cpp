/******************************************************************************
https://leetcode.com/problems/all-paths-from-source-lead-to-destination/

2.10.22
*******************************************************************************/

class Solution {
private:
    bool dfs(vector<vector<int>>& adjList, vector<int>& visited, int source, int destination){
        if (visited[source] == 1){
            return true;
        }   
        
        if (visited[source] == 0){
            return false;
        }
        
        if (adjList[source].size() == 0 && source != destination){
            return false;
        }
        
        visited[source] = 0;
        for (int neighbor : adjList[source]){
            if (dfs(adjList, visited, neighbor, destination) == false){
                return false;
            }   
            
        }
        visited[source] = 1;
        return true;
    }
    
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n, -1);
        vector<vector<int>> adjList(n);
        
        for (const auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
        }
        
        return dfs(adjList, visited, source, destination);
    }
};