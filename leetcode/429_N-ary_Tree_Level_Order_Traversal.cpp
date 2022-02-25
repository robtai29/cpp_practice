/******************************************************************************
https://leetcode.com/problems/n-ary-tree-level-order-traversal/

2.10.2022
*******************************************************************************/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        if (root == nullptr){
            return res;
        }
        
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            vector<int> level(size, 0);
            for (int i = 0; i < size; i++){
                Node* current = q.front();
                q.pop();
                level[i] = current -> val;
                for (auto& child : current -> children){
                    if (child != nullptr){
                        q.push(child);
                    }
                }
            }
             res.push_back(level);   
        }
        return res;
    }
};