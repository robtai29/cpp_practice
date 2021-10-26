/******************************************************************************
https://leetcode.com/problems/minimum-absolute-difference-in-bst/

10.26.21
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
void inorderTraverse(TreeNode* root, TreeNode*& prev, int& min_diff) {
    if (root-> left != nullptr){
        inorderTraverse(root->left, prev, min_diff);
    }
    
    min_diff = prev == nullptr ? min_diff : min(min_diff, abs(prev-> val - root -> val));
    prev = root;
    if (root -> right != nullptr){
        inorderTraverse(root->right, prev, min_diff);
    }
}
    
public:
int getMinimumDifference(TreeNode* root) {
    if (root == nullptr){
        return 0;
    }
   int min_diff = INT_MAX;
   TreeNode* previous = nullptr;
    inorderTraverse(root, previous, min_diff);
    return min_diff;
    
    }
};
