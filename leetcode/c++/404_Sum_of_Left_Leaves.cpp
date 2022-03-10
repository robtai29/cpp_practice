/******************************************************************************
https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        
        return sumOfLeftLeaves(root, false);
        
    }
    
    int sumOfLeftLeaves(TreeNode* node, bool isLeft){
        if (node == nullptr){
            return 0;
        }
        bool isLeave = node -> left == nullptr && node -> right == nullptr;
        int val = 0;
        if (isLeave && isLeft){
            val = node -> val;
        }
        
        return val + sumOfLeftLeaves(node -> left, true) + sumOfLeftLeaves(node -> right, false);
        
    }
    
    
};