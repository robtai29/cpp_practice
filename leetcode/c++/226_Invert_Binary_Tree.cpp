/******************************************************************************
https://leetcode.com/problems/invert-binary-tree/

10.7.2021, 1.20.22
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
    if (root == nullptr){
        return nullptr;
    }
    
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        swap(current-> left, current-> right);
        
        if (current -> left){
            q.push(current -> left);
        }
        
        if (current -> right){
            q.push(current -> right);
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

/*
class Solution {
public:
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr){
        return root;
    }
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()){
        TreeNode* current = s.top();
        s.pop();
        swap(current -> left, current-> right);
            if (current -> left){
            s.push(current -> left);
            }
            if (current -> right){
            s.push(current -> right);
            }
        
        }
        return root;   
    }
};
*/
