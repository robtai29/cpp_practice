/******************************************************************************
https://leetcode.com/problems/insert-into-a-binary-search-tree/

10.3.21
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
      void insertBSTHelper(TreeNode*& node, int val){
          if (node == nullptr){
              node = new TreeNode(val);
              return;
          }
          
          if (val > node -> val){
              
              insertBSTHelper(node-> right, val);
          }else{
              insertBSTHelper(node-> left, val);
          }
      }
    
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        insertBSTHelper(root, val);   
        return root;
    }
};