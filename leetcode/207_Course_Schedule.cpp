/******************************************************************************
https://leetcode.com/problems/course-schedule/

1.6.2022, 1.14.2022
*******************************************************************************/

class Solution {
private:
    bool dfsCheckCycle(int vertex, vector<int>& visit, vector<vector<int>>& graph){
        if (visit[vertex] == 2){
            return false;
        }
        
        if (visit[vertex] == 1){
            return true;
        }
        
        //check to see if dfs traversal will come back to the starting vertex 
        visit[vertex] = 1;
        for (int neighbor : graph[vertex]){
            if (dfsCheckCycle(neighbor, visit, graph)){
                return true;
            }
        }
        visit[vertex] = 2;
        return false;
    }
    
public:
    //use dfs
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //build graph first
        vector<vector<int>> adjList(numCourses);
        for (const auto& prereq : prerequisites){
            adjList[prereq[1]].push_back(prereq[0]);
        }
        
        // 0 - unseen, 1-visiting, 2 -visited
        vector<int> visit(numCourses, 0); 
        
        for (int i = 0; i < numCourses; i++){
            if (dfsCheckCycle(i, visit, adjList)){
                return false;
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //kahn's algorithm
        vector<vector<int>> adjList(numCourses); //adj list where index represents the class
        vector<int> indegrees(numCourses, 0);
        
        for (auto pair : prerequisites){
            indegrees[pair[0]]++;
            adjList[pair[1]].push_back(pair[0]);
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            if (indegrees[i] == 0){
                q.push(i);
                indegrees[i] = -1; //mark it as visited
            }
        }
        
        int visited = 0;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            visited++;
            for (int i = 0; i < adjList[current].size(); i++){
                if (--indegrees[adjList[current][i]] == 0){
                    q.push(adjList[current][i]);
                    indegrees[adjList[current][i]] = -1;
                }
            }
        }
        return visited == numCourses;
    }
};
*/