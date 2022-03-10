/******************************************************************************
https://leetcode.com/problems/path-sum/

7.8.2021
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr){
            return false;
        }
        
        bool isLeaf = root -> left == nullptr && root -> right == nullptr;
        targetSum -=  root -> val;
        if (!isLeaf){
            return false || hasPathSum(root -> left, targetSum) ||hasPathSum(root -> right, targetSum);
        }else{
            
            return targetSum == 0; 
        }
        
        
        
    }
};