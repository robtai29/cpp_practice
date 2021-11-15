/******************************************************************************
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/submissions/

11.14.21
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
    //dfs recursive
    void levelOrderHelper(TreeNode* node, int level, vector<vector<int>>& result){
        if (node == nullptr){
            return;
        }
        
        if (level == result.size()){
            result.push_back(vector<int>{});
        }
        
        result[level].push_back(node -> val);
        
        levelOrderHelper(node -> left, level + 1, result);
        levelOrderHelper(node -> right, level + 1, result);
    }
public:
    //bfs
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        
        vector<vector<int>> res;
        levelOrderHelper(root, 0, res);
        reverse(res.begin(), res.end());
        return res;
    }
};

/*
    //bfs
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr){
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size, 0);
            for (int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                v[i] = node -> val;
                
                if (node-> left){
                    q.push(node -> left);
                }
                
                if (node -> right){
                    q.push(node -> right);
                }

            }
            
            res.insert(res.begin(), v);
        }
            return res;
    }
*/