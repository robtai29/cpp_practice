/******************************************************************************
https://leetcode.com/problems/invert-binary-tree/

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
public:
TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* current = s.top();
        s.pop();
        
        if(current != nullptr){
            
            swap(current-> left, current-> right);
            s.push(current -> left);
            s.push(current -> right);
        }
    }
    return root;
}
};

/*
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr){
            return root;
        }
        
        swap(root-> left, root-> right);
        invertTree(root-> left);
        invertTree(root -> right);
        
        return root;
    }
*/