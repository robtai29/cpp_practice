/******************************************************************************
https://leetcode.com/problems/binary-tree-level-order-traversal/

10.3.2021
*******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void levelOrder(TreeNode* node, vector<vector<int>>& v, int depth){
        if (node == nullptr){
            return;
        }
        if (v.size() == depth){
            v.push_back(vector<int>());
        }
        v[depth].push_back(node-> val);
        
        levelOrder(node-> left, v, depth +1);
        levelOrder(node -> right, v, depth +1);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root, res, 0);
        return res;
    }
};
    
    /*
       vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        vector<int> level;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            
            TreeNode* current = q.front();
            q.pop();
            if (current == nullptr){
                if (!q.empty()){
                q.push(nullptr);   //signify end of level;
                }
                
                res.push_back(level);
                level.clear();
                
            }else {
                level.push_back(current -> val);
                if (current -> left != nullptr){
                    q.push(current-> left);
                }
                
                if (current -> right != nullptr){
                    q.push(current -> right);
                }
                
            }
        }
        return res;
        */
