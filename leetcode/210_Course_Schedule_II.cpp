/******************************************************************************
https://leetcode.com/problems/course-schedule-ii/

1.14.2022
*******************************************************************************/

class Solution {
private:
    bool dfsCheckCycle(int vertex, vector<vector<int>>& adjList, vector<int>& visit, vector<int>& res){
        if (visit[vertex] == 1){
            return true;  //true - cycle exists, false otherwise;
        }
        
        if (visit[vertex] == 2){
            return false;
        }
        
        visit[vertex] = 1;
        for (int neighbor : adjList[vertex]){
            if (dfsCheckCycle(neighbor, adjList, visit, res)){
                return true;
            }
        }
        
        visit[vertex] = 2;
        res.push_back(vertex);
        return false; //no cycle exists
    }
    
public:
    //dfs
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //build adjList
        vector<vector<int>> adjList(numCourses);
        vector<int> visit(numCourses, 0);  // 0 - unvisited, 1 = visiting (check cycle), 2 - visited
        
        for (const auto& pair : prerequisites){
            adjList[pair[1]].push_back(pair[0]);
        }
        
        vector<int> res;
        
        for (int i = 0; i < numCourses; i++){
            if (dfsCheckCycle(i, adjList, visit, res)){
                return vector<int>{};
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

/*
class Solution {
public:
    //Kahn's algo
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        
        //build graph
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        
        for (const auto& pair : prerequisites){
            indegrees[pair[0]]++;
            adjList[pair[1]].push_back(pair[0]);
        }
        
        queue<int> q;
        
        for (int i = 0; i < numCourses; i++){
            if (indegrees[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            res.push_back(vertex);
            for (int neighbor : adjList[vertex]){
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
};
*/