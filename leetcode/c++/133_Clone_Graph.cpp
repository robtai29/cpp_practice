/******************************************************************************
https://leetcode.com/problems/clone-graph/

1.2.2022
*******************************************************************************/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }
        unordered_map<Node*, Node*> m;
        m[node] = new Node(node -> val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* current = q.front();
            q.pop();
            for (Node* neighbor : current -> neighbors){
                   if (m.find(neighbor) == m.end()){
                       m[neighbor] = new Node(neighbor -> val);
                       q.push(neighbor);
                   }
                    m[current] -> neighbors.push_back(m[neighbor]);
            }
        }
            return m[node];
    }
};