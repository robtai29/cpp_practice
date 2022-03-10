/******************************************************************************
https://leetcode.com/problems/balanced-binary-tree/

11.17.2021
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
//improved version
class Solution {
private:
    int balancedHeight(TreeNode* node){
        if (node == nullptr){
            return 0;
        }
        
        int left = balancedHeight(node -> left);
        int right = balancedHeight(node -> right);
        
        if (left == -1 || right == -1){
            return -1;
        }
        
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        
        return balancedHeight(root) != -1;
        
    }
};

/*
//primitive version
class Solution {
private:
    int height(TreeNode* node){
        if (node == nullptr){
            return 0;
        }
        
        return 1 + max(height(node -> left), height(node -> right));
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        
        int left = height(root -> left);
        int right = height(root -> right);
        
        return abs(left - right) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
        
    }
};
*/