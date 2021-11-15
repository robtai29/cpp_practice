/******************************************************************************
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

11.13.2021
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
void zigzagTravel(TreeNode* node, vector<vector<int>>& result, int level){
    if (node == nullptr){
        return;
    }
    
    if (result.size() == level){
        result.push_back(vector<int>{});
    }
    
    if (level % 2 == 0){
        result[level].push_back(node -> val);
    }else{
        result[level].insert(result[level].begin(), node-> val);
    }
    
    zigzagTravel(node->left, result, level + 1);
    zigzagTravel(node->right, result, level + 1);
}
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzagTravel(root, res, 0);
        return res;
    }
};

/*
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        bool zigzag = false;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size, 0);
            for (int i = 0; i < size; i++){
                    TreeNode* current = q.front();
                    q.pop();
                    if (zigzag){
                        v[size-1-i] = current-> val;
                    }else{
                        v[i] = current -> val;
                    }
                
                    if (current-> left){
                        q.push(current-> left);
                    } 
                    if (current-> right){
                        q.push(current-> right);
                    } 
            }
                res.push_back(v);
                zigzag = !zigzag;
        }
        return res;
    }
*/