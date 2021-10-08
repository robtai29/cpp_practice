/******************************************************************************
https://leetcode.com/problems/binary-tree-postorder-traversal/

10.7.2021
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
    void postorderTraversal(TreeNode* node, vector<int>& v){
        if (node == nullptr){
            return;
        }
        
        postorderTraversal(node-> left, v);
        postorderTraversal(node-> right, v);
        v.push_back(node-> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postorderTraversal(root, v);
        return v;
    }
};