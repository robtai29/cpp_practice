/******************************************************************************
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

10.8.2021
*******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr){
            return root;
        }
        
        TreeNode* max = p;
        TreeNode* min = q;
        
        if (q-> val > p-> val){
            swap(max, min);
        }
        
        while (root-> val > max -> val || root -> val < min -> val){
            if (root -> val > max -> val){
                root = root -> left;
            }else if (root -> val < min -> val){
                root = root -> right;
            }
        
        }
        return root;
    }
};