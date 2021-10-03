/******************************************************************************
https://leetcode.com/problems/search-in-a-binary-search-tree/

9.27.21
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
    TreeNode* searchBST(TreeNode* root, int val) {
    
        if (root == nullptr || root -> val == val){
            return root;
        }
        
        TreeNode* current = root;
        while (current != nullptr){
            if (current -> val > val){
                current = current -> left;
                
            }else if (current -> val < val){
                current = current -> right;
            }else {
                return current;
            }
        }
        return current;
    }
};
/*
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr){
            return root;
        }
        
        if (root-> val > val){
            return searchBST(root-> left, val);
        }else if (root -> val < val){
            return searchBST(root-> right, val);
        }else{
            return root;
        }
    }
*/